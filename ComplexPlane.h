#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H

#include <vector>
#include <complex>

namespace julia
{

// This reduces the amount of clutter in the code below
typedef std::complex<double> Complex; // size has to be 2

class ComplexPlane
{
  public:

    // This constructor has input parameters with default values.
    // Research how this works.
    ComplexPlane(const double llcx = -2.0, 
		 const double llcy = -2.0, 
		 const double urcx =  2.0, 
		 const double urcy =  2.0); //✓
   ~ComplexPlane(){}

    // copy constructor
    ComplexPlane( const ComplexPlane& a ); //✓
    // constructor for initializing all values in the array to the input value
    ComplexPlane( const Complex& a );

    // copy assignment
    ComplexPlane& operator=(const ComplexPlane& a ); //✓
    // assign all members of the array to the input complex value.
    ComplexPlane& operator=(const Complex& a );

    // For the next 8 operator overloads, a new ComplexPlane object has to be created and returned. 
    // These are not operations applied "in-place".  
    //One  of theese is for adding complex plane objects and other is for adding a complex number
    // Add the input value to all members of the array
    ComplexPlane operator+(const Complex& a );
    // Subtract the input value from all members of the array
    ComplexPlane operator-(const Complex& a );
    // Divide all members of the array by the input value
    ComplexPlane operator/(const Complex& a );
    // Multiple all members of the array by the input value
    ComplexPlane operator*(const Complex& a );

    // Add to each member of the array, the corresponding member of the input object
    ComplexPlane operator+(const ComplexPlane& a );
    // Subtract form each member of the array, the corresponding member of the input object
    ComplexPlane operator-(const ComplexPlane& a );
    // Divide each member of the array by the corresponding member of the input object
    ComplexPlane operator/(const ComplexPlane& a );
    // Multiply each member of the array with the corresponding member of the input object
    ComplexPlane operator*(const ComplexPlane& a );



    // Remember:  friend functions and operators are not class members, but 
    // they can access private class data.
    friend ComplexPlane operator+(const Complex& a, const ComplexPlane& b);
    friend ComplexPlane operator-(const Complex& a, const ComplexPlane& b);
    friend ComplexPlane operator/(const Complex& a, const ComplexPlane& b);
    friend ComplexPlane operator*(const Complex& a, const ComplexPlane& b);

    friend ComplexPlane exp(const ComplexPlane& b);
    friend ComplexPlane cos(const ComplexPlane& b);
    friend ComplexPlane sin(const ComplexPlane& b);
    friend ComplexPlane sqrt(const ComplexPlane& b);
    friend ComplexPlane pow(const ComplexPlane& b, const double n);

    // These two "getter" methods just return values of private parameters
    const size_t& nx() const; //✓
    const size_t& ny() const; //✓

    // This method returns the complex math operation:
    //     abs(z)/R
    // for the complex value z found at location (i,j)
    double scaled_magnitude( const size_t i, const size_t j ) const;


  private:

    // Why are these three parameters static?  What other approaches toward the
    // same end might there be? Food for thought.
    static const size_t Nx;
    static const size_t Ny;
    static const double R;

    std::vector<Complex> data;

};

// Here we declare the functions that were designated as friend 
// functions in the ComplexPlane class.
// These operators and functions perform the same concepts as the corresponding class methods. 
// It will help you to think about why they have been declared here as functions and not as class methods.
ComplexPlane operator+(const Complex& a, const ComplexPlane& b);
ComplexPlane operator-(const Complex& a, const ComplexPlane& b);
ComplexPlane operator/(const Complex& a, const ComplexPlane& b);
ComplexPlane operator*(const Complex& a, const ComplexPlane& b);

ComplexPlane exp(const ComplexPlane& b);
ComplexPlane cos(const ComplexPlane& b);
ComplexPlane sin(const ComplexPlane& b);
ComplexPlane sqrt(const ComplexPlane& b);
ComplexPlane pow(const ComplexPlane& b, const double n);

}
#endif
