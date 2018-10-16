// Workshop 5: operator overloading
// File: w5_in_lab.cpp
// Version: 2.0
// Date: 2018/10/15
// Author: Tenzin Shedup
// Student # 120664180
#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

namespace sict {
	class Fraction {
		int num;
		int denom;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		Fraction();
		Fraction(int num, int denom);
		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction& rhs) const;
	};
}
#endif 

