// TODO: add
#ifndef SICT_Passenger_H_
#define SICT_Passenger_H_
#define MAX 19

namespace sict
{

	class Passenger
	{
		//private data members
		char pass_Name[MAX];
		char dest[MAX];
		int dept_Yr;
		int dept_Mon;
		int dept_Day;

	public:
		//constructor sets passenger object to a safe empty stat
		Passenger(const char* Name, const char* Destination, int Year, int Month, int day);
		Passenger(const char* Name, const char* Destination);
		Passenger();
		const char* name();
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;


	};
}
#endif
