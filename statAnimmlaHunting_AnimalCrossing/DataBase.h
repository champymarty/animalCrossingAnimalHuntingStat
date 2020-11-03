#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Character.h"
#include "Specie.h"
#include "SpecieString.h"

class DataBase{

public:
	DataBase();

	void saveData();
	bool addVillager(std::string nom);
	bool deleteVillager(std::string nom);

	bool addVillagerToSearch(std::string nom);
	bool deleteVillagerToSearch(std::string nom);

	void printVillage()const;
	void printVillagerToSearch()const;
private:
	
	int NUMBER_OF_SPECIES = 35;
	std::vector<Character> availableCharacter;
	std::vector<Character> villagers;
	std::vector<Character> villagersToSearch;

	std::vector<int> numberOfAvailableCharacterPerSpecie = std::vector<int>(NUMBER_OF_SPECIES,0);
	SpecieString specieStr;
	

	const std::string FICHIER_AVAILABLE_CHATACTER = "availableCharacters.txt";
	const std::string FICHIER_VILLAGERS = "villagers.txt";
	const std::string FICHIER_VILLAGERS_SEARCH = "villagers_search.txt";

	void readDataBase();
	void readFile(const std::string fileName, std::vector<Character>& vector);
	void writeData(const std::string fileName, const std::vector<Character>& vector)const;
	void initialiseLists();
	int getNumberOfAvailableCharacterInSpecificSpecie(const Specie specie) const;
	std::vector<std::string> splitString(const std::string& string)const;
	int searchCharacter(std::string nom, const std::vector<Character>& vector)const;
	void sortData();

};

#endif

