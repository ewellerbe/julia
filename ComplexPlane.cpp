
#include "ComplexPlane.h"
#include <iostream>

using namespace julia;
using namespace std;


const double ComplexPlane::R = 2.0;
const size_t ComplexPlane::Nx = 1024;
const size_t ComplexPlane::Ny = 1024;

// Constructor sets up a 2D array of points in the complex plane, stored as a 1D std::vector array.
ComplexPlane::ComplexPlane(const double llcx, const double llcy, const double urcx, const double urcy)
{
   Complex default_value(0.0,0.0);
   data.resize( Nx*Ny, default_value );

   for(size_t j=0;j<Ny;j++){
      double imag = ((double)j)*(urcy-llcy)/Ny + llcy;
      for(size_t i=0;i<Nx;i++){
         double real = ((double)i)*(urcx-llcx)/Nx + llcx;
         size_t index = i + Nx*j;
	      data[index] = Complex(real,imag);
      }
   }
}

// copy constructor
ComplexPlane::ComplexPlane( const ComplexPlane& a )
{
   //cout << "Copy constructor called" << endl;
   data = a.data;
}


// constructor for initializing all values in the array to the input value
ComplexPlane::ComplexPlane( const Complex& a )
{
   //cout << "COPY CONSTRUCTOR WITH COMPLEX" << endl;
   Complex default_value(0.0,0.0);
   data.resize( Nx*Ny, default_value );

   for(size_t i=0; i < data.size(); i++){
      data[i] = a;
   }
}

// copy assignment
ComplexPlane& ComplexPlane::operator=(const ComplexPlane& a )
{
   //cout << "Assignment operator called" << endl;
   data = a.data;
   return *this;
}


// assign all members of the array to the input complex value.
ComplexPlane& ComplexPlane::operator=(const Complex& a )
{

//cout << "=========================" << endl;
 Complex default_value(0.0,0.0);
 data.resize( Nx*Ny, default_value );

 for(size_t i=0; i < data.size(); i++){
    data[i] = a;
 }

 return *this;
}

// Add the input value from all members of the array
ComplexPlane ComplexPlane::operator+(const Complex& a ) // Adds complex numbers to every element of data of complex plane
{

   //cout<< "+ OPERATOR CALLED + " << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] + a;
      }
   }
   return plane;

}
// Subtract the input value from all members of the array
ComplexPlane ComplexPlane::operator-(const Complex& a )
{
   //cout<< "- OPERATOR CALLED - " << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] - a;
      }
   }
   return plane;
}
// Divide all members of the array by the input value
ComplexPlane ComplexPlane::operator/(const Complex& a )
{

   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] / a;
      }
   }
   return plane;
}

// Multiple all members of the array by the input value
ComplexPlane ComplexPlane::operator*(const Complex& a )
{
   //cout<< "* OPERATOR CALLED * " << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] * a;
      }
   }
   return plane;
}

// Add to each member of the array, the corresponding member of the input object
ComplexPlane ComplexPlane::operator+(const ComplexPlane& a ) // Adds 2 classes
{
   //cout<< "+ operator called +" << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] + a.data[index];

      }
   }
   return plane;
}

// Subtract form each member of the array, the corresponding member of the input object
ComplexPlane ComplexPlane::operator-(const ComplexPlane& a )
{
   //cout<< "- operator called -" << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] - a.data[index];
      }
   }
   return plane;
}

// Divide each member of the array by the corresponding member of the input object
ComplexPlane ComplexPlane::operator/(const ComplexPlane& a )
{
   //cout<< "/ operator called /" << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
          size_t index = i + Nx*j;
          plane.data[index] = data[index] / a.data[index];
      }
   }
   return plane;
}

// Multiply each member of the array with the corresponding member of the input object
ComplexPlane ComplexPlane::operator*(const ComplexPlane& a )
{
   //cout<< "* operator called *" << endl;
   ComplexPlane plane(a);

   for(size_t j = 0; j < Ny; j++){
      for(size_t i = 0; i < Nx; i++) {
         size_t index = i + Nx*j;

         plane.data[index] = data[index] * a.data[index];
      }
   }

   return plane;
}


// Declaration of functions that were designated as friend
ComplexPlane julia::operator+(const Complex& a, const ComplexPlane& b)
{
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = a + b.data[index];
       }
    }
    return plane;
}

ComplexPlane julia::operator-(const Complex& a, const ComplexPlane& b)
{
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = a - b.data[index];
       }
    }
    return plane;
}

ComplexPlane julia::operator/(const Complex& a, const ComplexPlane& b)
{
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = a / b.data[index];
       }
    }
    return plane;
}

ComplexPlane julia::operator*(const Complex& a, const ComplexPlane& b)
{
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = a * b.data[index];
       }
    }
    return plane;
}

ComplexPlane julia::exp(const ComplexPlane& b) {
    ComplexPlane plane(b);

    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
          plane.data[index] = exp(b.data[index]);
       }
    }
    return plane;
}

ComplexPlane julia::cos(const ComplexPlane& b){
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = cos(b.data[index]);
       }
    }
    return plane;
}

ComplexPlane julia::sin(const ComplexPlane& b){
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = sin(b.data[index]);
       }
    }
    return plane;
}


ComplexPlane julia::sqrt(const ComplexPlane& b){
    ComplexPlane plane(b);
    for(size_t j = 0; j <  b.Ny; j++){
       for(size_t i = 0; i < b.Nx; i++) {
           size_t index = i + b.Nx*j;
           plane.data[index] = sqrt(b.data[index]);
       }
    }
    return plane;
}

ComplexPlane julia::pow(const ComplexPlane& b, const double n) {

ComplexPlane plane(b);
for(size_t j = 0; j <  b.Ny; j++){
   for(size_t i = 0; i < b.Nx; i++) {
       size_t index = i + b.Nx*j;
       plane.data[index] = pow(b.data[index],n);
   }
}
return plane;
}

// These two "getter" methods just return values of private parameters
const size_t& ComplexPlane::nx() const {return Nx;}
const size_t& ComplexPlane::ny() const {return Ny;}


  // This method returns the complex math operation:
    //     abs(z)/R
    // for the complex value z found at location (i,j)
double ComplexPlane::scaled_magnitude( const size_t i, const size_t j ) const
{
   size_t index = i + Nx*j;
   return abs(data[index])/R;
}
