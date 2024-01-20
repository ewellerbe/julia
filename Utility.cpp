#include "Utility.h"
#include "ComplexPlane.h"
#include "ColorLUT.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace julia;

void julia::WriteAsciiPPM( const std::string& filename, const ComplexPlane& p, const ColorLUT& c )
{
   std::ofstream out; 
   out.open(filename);

   out << "P3 " << p.nx() << " " << p.ny() << " " << c.max_value() << std::endl;
   for(size_t j=0;j<p.ny();j++)
   {
      for(size_t i=0;i<p.nx();i++)
      {
         int r,g,b;
	 c( p.scaled_magnitude(i,j), r, g, b);
	 out << r << " " << g << " " << b << std::endl;
      }
   }
   out.close();  
}


