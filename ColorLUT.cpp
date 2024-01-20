#include "ColorLUT.h"
#include <cmath>
#include <iostream>

using namespace julia;

ColorLUT::ColorLUT(double gam) :
   gamma (gam)
{
   // Blue Ridge
   r_bands.push_back(58.0);
   g_bands.push_back(73.0);
   b_bands.push_back(88.0);

   // Bowman Field
   r_bands.push_back(86.0);
   g_bands.push_back(97.0);
   b_bands.push_back(39.0);

   // Anna's Lace
   r_bands.push_back(249.0);
   g_bands.push_back(228.0);
   b_bands.push_back(152.0);

   // Benal Stripe
   r_bands.push_back(16.0);
   g_bands.push_back(16.0);
   b_bands.push_back(16.0);

   // Hartwell Moon
   r_bands.push_back(212.0);
   g_bands.push_back(201.0);
   b_bands.push_back(158.0);

   // Innovation
   r_bands.push_back(134.0);
   g_bands.push_back(137.0);
   b_bands.push_back(140.0);

   // Howard's Rock:
   r_bands.push_back(104.0);
   g_bands.push_back(92.0);
   b_bands.push_back(83.0);


      // Regalia
   r_bands.push_back(82.0);
   g_bands.push_back(45.0);
   b_bands.push_back(128.0);


}


// This implementation ramps between two colors, with indices 0 and 1.  
void ColorLUT::operator()(const double& value, int& r, int& g, int& b) const
{
   if(value > 1.0 || value < 0.0 )
   {
      r = 0;
      g = 0;
      b = 0;
      return;
   }

   double x = std::pow(value,gamma) * 7;
   size_t high_index = x + 1;
   size_t low_index = x;

   double weight = x - (double)low_index;

   float rr = r_bands[low_index] * (1.0-weight) + r_bands[high_index] * weight;
   float gg = g_bands[low_index] * (1.0-weight) + g_bands[high_index] * weight;
   float bb = b_bands[low_index] * (1.0-weight) + b_bands[high_index] * weight;

   r = (int)rr;
   g = (int)gg;
   b = (int)bb;
}
