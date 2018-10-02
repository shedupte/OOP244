#define _CRT_SECURE_NO_WARNINGS
#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict
{
	Passenger::Passenger(const char * Name, const char * Destination, int Year, int Month, int Day)
	{
		bool Year_ck = 2017 < Year < 2021;
		bool Month_ck = 0 < Month < 13;
		bool Day_ck = 0 < Day < 32;
		bool Name_ck = Name != nullptr;
		bool Dest_ck = Destination != nullptr;

		if (Year_ck && Month_ck && Day_ck && Name_ck && Dest_ck)
		{
			strncpy(pass_Name, Name, MAX);
			pass_Name[MAX - 1] = '\0';
			strncpy(dest, Destination, MAX);
			dept_Yr = Year;
			dept_Mon = Month;
			dept_Day = Day;

		}
		else
		{
			Passenger::Passenger();
		}
	}
	Passenger::Passenger()
	{
		pass_Name[0] = { '\0' };
		dest[0] = { '\0' };
		dept_Day = 0;
		dept_Mon = 0;
		dept_Yr = 0;
	}
	/*::Passenger(const char* Name, const char* Destination)
	{
		if (Name != nullptr && Destination != nullptr)
		{
			strncpy(pass_Name, Name, MAX);
			pass_Name[MAX - 1] = '\0';
			strncpy(dest, Destination, MAX);
			

		}
		else
		{
			*this = Passenger();
		}
	}*/
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
		bool check = strlen(pass_Name) > 0 && strlen(dest) > 0;
		return !check;
	}
	void Passenger::display() const
	{
		if (!isEmpty())
		{
			cout << this->pass_Name << " - " << this->dest << endl;
		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}


}


