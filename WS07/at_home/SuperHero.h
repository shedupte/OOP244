#ifndef SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H_
#include "Hero.h"

namespace sict 
{
	class SuperHero: public Hero
	{
		int m_BonusAttack;

		int m_Defend;
	
	public:
		SuperHero();

		SuperHero(const char* name, int health, int attack, int bonus, int defend);

		int attackStrength() const;

		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
	
#endif 
