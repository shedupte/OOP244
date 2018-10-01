#define _CRT_SECURE_NO_WARNINGS
#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict
{

	Passenger::Passenger()
	{
		pass_Name[0] = { '\0' };
		dest[0] = { '\0' };
	}
	Passenger::Passenger(const char* Name, const char* Destination)
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
			cout << this->pass_Name << "-" << this->dest << endl;
		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}


}


