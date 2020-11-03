#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "Specie.h"

class Character{
public:
	Character(std::string nom, Specie specie);
	Character(std::string nom, std::string specie);
	Character();

	std::string getNom() const;
	Specie getSpecie() const;
	friend std::ostream& operator<<(std::ostream& outputStream, const Character& character);
private:
	std::string nom = "Nobody";
	Specie specie;
};

#endif

