#ifndef SICT_CRA_Account_H_
#define SICT_CRA_Account_H_


namespace sict
{
	const int max_name_length = 40;
	const int MIN_SIN = 100000000;
	const int MAX_SIN = 999999999;
	const int max_yrs = 4;


	class CRA_Account
	{
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void display() const;
		bool isEmpty() const;
		void set(int year, double balance);
		

	private:
		char family_name[max_name_length+1];
		char given_name[max_name_length+1];
		double yearly_balance[max_yrs];
		int tax_return_years[max_yrs];
		int return_years;
		int SIN;

	};


}
#endif