#pragma once
/*
Name:Tenzin Shedup
Student number:120664180
Email:tshedup@myseneca.ca
Workshop:Week_7
Date:NOV 5,2018
*/

#ifndef SICT_HERO_H_
#define SICT_HERO_H_
#include <iostream>
#define MAX_ROUNDS 100

using namespace std;

namespace sict {
	class Hero
	{
		char m_Name[40];
		int m_Health;
		int m_Attack_Strength;

	public:
		Hero();//fail safe if no information is recieved 

		Hero(const char*, int, int);// make sure it's valid, if so then store

		void operator-=(int attack);

		bool isAlive() const;

		int attackStrength() const;

		friend ostream& operator<<(ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif