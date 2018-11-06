#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <cstring>
#include <iostream>

namespace sict
{
	Hero::Hero()
	{
		//char m_Name = '\0';
		//int m_Health = 0;
		//int m_Attack_Strength = 0;
		
		/*Matrix complier issue as the variable were unused so I commented them out
		for the in-lab portion
		Probably need to uncomment them for the at home portion*/
	}

	Hero::Hero(const char* name, int health, int attack_Strength)
	{
		if (health < 0 || attack_Strength < 0)
		{
			Hero();
		}
		else
		{
			strncpy(m_Name, name, 20);
			m_Attack_Strength = attack_Strength;
			m_Health = health;
		}

	}

	void Hero::operator-=(int attack)
	{
		if (attack >= 0)
		{
			(*this).m_Health -= attack;
			if ((*this).m_Health <= 0)
			{
				(*this).m_Health = 0;
			}

		}
	}

	bool Hero::isAlive() const
	{
		return ((*this).m_Health > 0);

	}

	int Hero::attackStrength() const
	{
		int key = (*this).m_Attack_Strength;

		if (key <= 0)
			key = 0;

		return key;
	}

	ostream & operator<<(ostream & os, const Hero & hero)
	{
		if (hero.m_Name == 0)
		{
			os << "No hero";
		}
		else
		{
			os << hero.m_Name;
		}

		return os;
	}

	const Hero & operator*(const Hero & first, const Hero & second)
	{
		Hero temp1 = first;
		Hero temp2= second;

		const Hero *survior = &first;

		int round_Num = 0;
		for (size_t i = 0; i < MAX_ROUNDS&& round_Num == 0; i++)
		{
			temp1 -= temp2.attackStrength();
			temp2 -= temp1.attackStrength();

			if (!temp1.isAlive())
			{
				survior = &second;
				round_Num = i + 1;
			}
			else if (!temp2.isAlive())
			{
				survior = &first;
				round_Num = i + 1;
			}
		}

		cout << "Ancient Battle! " << temp1 << " vs " << temp2 << " : Winner is " << *survior << " in " << round_Num << " rounds." << endl;

		return *survior;
	}
}