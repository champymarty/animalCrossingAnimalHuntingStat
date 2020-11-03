#ifndef SPECIE_STRING_H
#define SPECIE_STRING_H
#include <string>
#include <unordered_map>
#include "Specie.h"

class SpecieString{
public:
	SpecieString();

	Specie stringToEnum(std::string string)const;
	std::string enumToString(const Specie specie)const;

	void toLowerCase(std::string& string) const;
	void toUpperCase(std::string& string) const;
private:
	std::unordered_map<std::string, Specie> umap;


};
#endif

