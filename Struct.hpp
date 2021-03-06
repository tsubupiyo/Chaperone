#pragma once

class Triangle
{
   public:
      int  a,  b,  c;   //vertex number
      int  n;           //triangle number
      int AB, BC, CA;   //Neighbor triangle number
   
   public:
      Triangle() noexcept;
      Triangle
      (
         int a_, int b_, int c_,
         int n_,
         int AB_, int BC_, int CA_
      ) noexcept;
};

Triangle::Triangle() noexcept
{
   a=b=c=INT_MAX;
   n=INT_MAX;
   AB=BC=CA=INT_MAX;
}

Triangle::Triangle
(
   int a_, int b_, int c_,
   int n_,
   int AB_, int BC_, int CA_
) noexcept
{
   a  =  a_;
   b  =  b_;
   c  =  c_;
   n  =  n_;
   AB = AB_;
   BC = BC_;
   CA = CA_;
}

