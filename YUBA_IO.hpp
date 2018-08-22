template<typename ELEMENTS>
void OutYUBA(const int& step, const ELEMENTS& elements, const std::string& file_name, const std::string& tag, bool trunc_f=false);

template<typename ELEMENTS>
void OutYUBA(const int& step, const ELEMENTS& elements, const std::string& file_name, const std::string& tag, bool trunc_f)
{
   std::ofstream ofs(file_name,(trunc_f)?(std::ios::trunc):(std::ios::app));
   ofs<<"# "<<tag<<" "<<step<<"\n";
   for(size_t i=0,size=elements.size();i<size;++i)
   {
      ofs<<elements.at(i)<<"\n";
   }
   ofs<<"\n";
   ofs.close();
}

void OutYUBA(const int& step, const std::vector<Vector3D>& elements, const std::string& file_name, const std::string& tag, bool trunc_f)
{
   std::ofstream ofs(file_name,(trunc_f)?(std::ios::trunc):(std::ios::app));
   ofs<<"# "<<tag<<" "<<step<<"\n";
   for(size_t i=0,size=elements.size();i<size;++i)
   {
      ofs<<i<<" "<<elements.at(i)<<"\n";
   }
   ofs<<"\n";
   ofs.close();
}

template<typename GETLINE, typename TIME_RANGE>
std::vector<Vector3D> get_next_Beads
(
   GETLINE& gl,
   const TIME_RANGE& tr
)
{
   std::vector<Vector3D> res;
   while(gl.is_open())
   {
      std::string tmp = gl.get();
      std::vector<std::string> vs;
      boost::algorithm::split(vs,tmp,boost::is_any_of(" "));
      if("#"==vs.at(0) && "Bead"==vs.at(1))
      {
         const int step = boost::lexical_cast<int>(vs.at(2));
         if(std::get<0>(tr)<=step && step<=std::get<1>(tr))
         {
            //read it!
            while(gl.is_open())
            {
               tmp = gl.get();
               boost::algorithm::split(vs,tmp,boost::is_any_of(" ")); 
               if(""==tmp){break;}
               if("#"==vs.at(0)){break;}
               //Bead-format: x y z
               res.push_back
               (
                  Vector3D
                  (
                     boost::lexical_cast<double>(vs.at(0)),
                     boost::lexical_cast<double>(vs.at(1)),
                     boost::lexical_cast<double>(vs.at(2))
                  ) 
               );
            }
            res.shrink_to_fit();
            return res;
         }
      }
   }
   throw std::out_of_range("end");
   return res;
}