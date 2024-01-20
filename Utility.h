#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace class1020
{

// forward declarations
class ComplexPlane;
class ColorLUT;

void WriteAsciiPPM( const std::string& filename, const ComplexPlane& p, const ColorLUT& c );


}
#endif
