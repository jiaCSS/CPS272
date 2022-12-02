#include "Complex.h"
#include<iostream>
#include<iomanip>
#include<string>
#include <sstream>
#include <cmath>
using namespace std;

//Constructor
Complex::Complex(double re, double im) :real(re), imag(im) {

}

//seter and getter
double Complex::getReal(void) const {

	return real;

} 


double Complex::getImaginary(void) const {

	return imag;
}  


void Complex::setReal(double real) {

	this->real = real;

}  


void Complex::setImaginary(double imag) {

	this->imag = imag;

} 

//conver input complex string to complex number
void Complex::convertStringToComplex(const string& complexString) {

	stringstream ss(complexString);
	ss >> real >> imag;

}

//output operator
ostream& operator<<(ostream& out, const Complex& theComplex) {

	out << "("<< theComplex.getReal() << " + " << theComplex.getImaginary() << "i"<<")";
	return out;
}
 
//input operator
istream& operator>>(istream& in, Complex& theComplex) {

	in >> theComplex.real >> theComplex.imag;
	cin.ignore(256, '\n');

	return in;

}

//addtion operator
Complex operator+(const Complex& lhs, const Complex& rhs) {

	double real = lhs.real + rhs.real;
	double imag = lhs.imag + rhs.imag;

	return Complex(real, imag);

}

//subtration operator
Complex operator-(const Complex& lhs, const Complex& rhs) {

	double real = lhs.real - rhs.real;
	double imag = lhs.imag - rhs.imag;

	return Complex(real, imag);

}

//multipliction operator
Complex operator*(const Complex& lhs, const Complex& rhs) {

	double real = (lhs.real * rhs.real)- (lhs.imag * rhs.imag);
	double imag = lhs.imag - rhs.imag;

	return Complex(real, imag);

}

//divistion operator
Complex operator/(const Complex& lhs, const Complex& rhs) {
	double real = 0.0;
	double imag = 0.0;

	if (rhs.real != 0 || rhs.imag != 0) {

		real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) / (pow(rhs.real, 2) + pow(rhs.imag, 2));
		imag = (lhs.imag * rhs.real - lhs.real * rhs.imag) / (pow(rhs.real, 2) + pow(rhs.imag, 2));
	}
	else {
		cout << "Invalid Enter for second complex.";
	}
	
	return Complex(real, imag);
}


