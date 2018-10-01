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

	public:
		//constructor sets passenger object to a safe empty stat
		Passenger();
		Passenger(const char* Name, const char* Destination);
		bool isEmpty() const;
		void display() const;


	};
}
#endif
