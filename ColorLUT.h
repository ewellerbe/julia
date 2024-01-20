#ifndef COLORLUT_H
#define COLORLUT_H

#include <vector>

namespace julia
{


class ColorLUT
{
  public:

    ColorLUT(double gamma = 1.0);
   ~ColorLUT(){}

    // Generate red, green, blue color from the input value.
    // This makes ColorLUT a function object, or functor
    void operator()(const double& value, int& red, int& green, int& blue) const;

    const int max_value() const { return 255; }

  private:

    double gamma;
    std::vector<float> r_bands;
    std::vector<float> g_bands;
    std::vector<float> b_bands;
};





}
#endif
