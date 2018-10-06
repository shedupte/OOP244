#define _CRT_SECURE_NO_WARNINGS
#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict
{
	Passenger::Passenger(const char * Name, const char * Destination, int Year, int Month, int Day)
	{
		bool isYearValid = (Year >= 2018) && (Year <= 2021);
		bool isMonthValid = (Month >= 1)  && (Month <= 12);
		bool isDayValid = (Day >= 1) && (Day <= 31);

		bool isNameEmpty = (Name == nullptr) || (Name[0] == '\0');
		bool isDestinationEmpty = (Destination == nullptr) || (Destination[0] == '\0');

		if ( isNameEmpty || isDestinationEmpty|| !isYearValid|| !isMonthValid || !isDayValid)
		{
			*this = Passenger();

		}
		else
		{
			strncpy(pass_Name, Name, MAX);
			pass_Name[MAX - 1] = '\0';
			strncpy(dest, Destination, MAX);

			dept_Yr = Year;
			dept_Mon = Month;
			dept_Day = Day;
		}
	}
	Passenger::Passenger()
	{
		pass_Name[0] = '\0';
		dest[0] = '\0';
		dept_Day = 0;
		dept_Mon = 0;
		dept_Yr = 0;
	}
	Passenger::Passenger(const char* Name, const char* Destination)
	{
		if (Name != nullptr && Destination != nullptr)
		{
			strncpy(pass_Name, Name, MAX);
			pass_Name[MAX - 1] = '\0';
			strncpy(dest, Destination, MAX);


			/*dept_Day = 01;
			dept_Mon = 10;
			dept_Yr = 2018;*/

			*this = Passenger(pass_Name, dest, 2018, 10, 01);
			

		}
		else
		{
			*this = Passenger();
		}
	}
	const char * Passenger::name()
	{
		return pass_Name;
	}
	bool Passenger::canTravelWith(const Passenger & pass) const
	{
		bool year = (*this).dept_Yr == pass.dept_Yr;
		bool month = (*this).dept_Mon == pass.dept_Mon;
		bool day = (*this).dept_Day == pass.dept_Day;
        bool check = day && month && year;

		return check;
	}
	bool Passenger::isEmpty() const
	{
		bool check = strlen(pass_Name) == 0 || strlen(dest) == 0 || dept_Day == 0 || dept_Mon == 0 || dept_Yr == 0;
		return check;
	}
	void Passenger::display() const
	{
		if (!isEmpty())
		{
			cout << this->pass_Name << " - " << this->dest << " on " << this->dept_Yr << "/"<< this->dept_Mon<< "/" << this->dept_Day << endl;
		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}


}


