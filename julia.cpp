
#include "ComplexPlane.h"
#include "ColorLUT.h"
#include "Utility.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
using namespace julia;


// Generates a four digit zero-padded number
// i.e. for input value 12, returns the string "0012".
// Padding frame numbers to have four digits like
// this is a standard approach and simplifies
// a lot of processing of images.
std::string padded_frame_number(int i)
{
   std::string result = std::to_string(i);
   if( i<1000){ result = "0" + result; }
   if( i<100){ result = "0" + result; }
   if( i<10){ result = "0" + result; }
   return result;
}


int main(int argc, char** argv)
{
   std::string fname_base = "julia";

   // The number of cycles. For the complicated case, we use -1
   int cycles = 2;
   if(cycles >= 2 )
   {
      fname_base = fname_base + std::to_string(cycles);
   }
   else
   {
      fname_base = fname_base + "complicated";
   }

   // Color Look Up Table to transform ComplexPlane values to RGB color values. s
   double gamma = 2;
   ColorLUT lut(gamma);
   fname_base = fname_base + "c";


   size_t julia_iterations = 10;
   fname_base = fname_base + "_iter" + std::to_string(julia_iterations);

   int number_of_frames = 100;
   fname_base = fname_base + "_frames" + std::to_string(number_of_frames);

   double half_length = 1.5;
   double center_x = 0.0;
   double center_y = 0.0;
   double llc_x = center_x - half_length;
   double llc_y = center_y - half_length;
   double urc_x = center_x + half_length;
   double urc_y = center_y + half_length;

   // Loop over the number of frames
   for( int frame=1;frame<number_of_frames+1;frame++)
   {
      std::cout << "\rFrame " << frame << "    " << std::flush;

      // The parameter theta is animated from 0.0 at the first
      // frame to two pi at the last frame
      float theta = (frame-1)*2.0*3.14159265/number_of_frames;

      // The parameter theta is used to create a "constant" valued
      // ComplexPlane, where every grid point holds the same value
      ComplexPlane c( Complex(std::cos(theta)*0.8, std::sin(theta)*0.8) );



      // The constructor here generates a value at every point of the
      // complex plane
      ComplexPlane z(llc_x,llc_y,urc_x,urc_y);
      for(size_t iter=0;iter<julia_iterations;iter++)

	 if(cycles == 2)
	 {
	    // Julia set with a two cycle
	    z = z*z + c;
	 }
	 else if(cycles == 3)
	 {
	    // Julia set with a three cycle
	    z = z*z*z + c;
	 }
	 else if(cycles == 4)
	 {
	    // Julia set with a four cycle
	    z = z*z*z*z + c;
	 }
	 else
	 {
	    // a bit more complicated set
       z = c*z*(1.0-z);
	 }
      }

      // After iterations, we write the ComplexPlane array as an image.
      // The pixel RGB values is produced from a Look Up Table that
      // maps values from the ComplexPlane to colors stored in the LUT.
      // This is for a simple ppm image.  The file name contains the
      // frame number so that we can see all of them and generate a movie.
      // The function WriteAsciiPPM is in Utility.h, Utility.cpp.
      std::string fname = fname_base + "." + padded_frame_number(frame) + ".ppm";
      WriteAsciiPPM( fname, z, lut );
   }


   std::string mkmovie = "ffmpeg -i " + fname_base + ".%04d.ppm  -preset slow -codec:a libfdk_aac -b:a 128k -codec:v libx264 -pix_fmt yuv420p -b:v 4500k -minrate 4500k -maxrate 9000k -bufsize 9000k -vf scale=-1:1080 ./" + fname_base + ".mp4";

   std::cout << "\nConverting to movie using the system command\n\t" + mkmovie << std::endl;
   // system executes the input string as a commandon the command line
   return system(mkmovie.c_str());
}
