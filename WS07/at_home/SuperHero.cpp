//damage calculation 
/* Damage(A) = (Attack of B + AttackBonus of B) - DefendStrength of A
Damage (B)= (Attack of A + AttackBonus of A) - DefendStrength of B*/
#include "SuperHero.h"
#include <iostream>

using namespace std;
using namespace sict;

namespace sict {

	
	SuperHero::SuperHero()
	{
		m_BonusAttack = 0;
		m_BonusAttack = 0;
	}

	SuperHero::SuperHero(const char * name, int health, int attack, int bonus, int defend) :
		Hero::Hero(name, health, attack){
		m_BonusAttack = bonus;
		m_Defend = defend;
	}

	int SuperHero::attackStrength() const
	{
		int key = Hero::attackStrength() + m_BonusAttack;
		if (Hero::attackStrength() == 0)
		{
			key = 0;
		}

		return key;
	}

	int SuperHero::defend() const
	{
		int key = m_Defend;
		if (m_Defend == 0)
		{
			key = 0;
		}
		return key;
	}


	const SuperHero& operator*(const SuperHero & first, const SuperHero & second)
	{
		SuperHero left = first;
		SuperHero right = second;
		
		const SuperHero *winner = &left;

		int Round_Num = 0;

		for (int i = 0; i < MAX_ROUNDS && Round_Num == 0; i++)
		{
			left -= right.attackStrength() - left.defend();
			right -= left.attackStrength() - right.defend();

			if (!left.isAlive())
			{
				winner = &second;

				Round_Num = i + 1;
			}
			else if (!right.isAlive())
			{
				winner = &first;
				Round_Num = i + 1;
			}
			
		}
		cout << "Super Fight! " << first << " vs " << second << " : Winner is " << *winner << " in " << Round_Num << endl;
		return *winner;
	}
}