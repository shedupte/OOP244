#include <iostream>
#include "Fraction.h"
using namespace std;
using namespace sict;

namespace sict {

	int Fraction::max() const
	{
		int greater;
	    (num > denom) ? greater = num : greater = denom;
		return greater;
	}

	int Fraction::min() const
	{
		int lesser; 
		(num < denom) ? lesser = num : lesser = denom;
		return lesser;
	}

	void Fraction::reduce()
	{
		int GCD = gcd();
		num = num / GCD;
		denom = denom / GCD;
	}

	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	Fraction::Fraction()
	{
		num = 0;
		denom = 0;
	}

	Fraction::Fraction(int NUM, int DENOM)
	{
		bool negChk = NUM < 0 || DENOM < 0;
		if (negChk) {
			*this = Fraction();
		}
		if(!negChk)
		{
			num = NUM;
			denom = DENOM;
			reduce();
		}
	}

	bool Fraction::isEmpty() const
	{
		return  (num == 0 && denom == 0);
	}

	void Fraction::display() const
	{
		if (!isEmpty() && denom != 1)
			cout << num << "/" << denom;
		else if (!isEmpty() && denom == 1)
			cout << num;
		else 
			cout << "no fraction stored";
	}

	Fraction Fraction::operator+(const Fraction & rhs) const
	{
		Fraction temp;//left opreand
		//temp = rhs;

		if (!isEmpty() && !rhs.isEmpty())
		{	
			
			temp.num = ((rhs.num * denom) + (rhs.denom * num));
			temp.denom = (rhs.denom * denom);
			temp.reduce();
		}

		return temp;
	}
}
  
