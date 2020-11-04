#include "DataBase.h"

DataBase::DataBase(){
	readDataBase();
	initialiseLists();
}

void DataBase::saveData(){
	writeData(FICHIER_AVAILABLE_CHATACTER, availableCharacter);
	writeData(FICHIER_VILLAGERS, villagers);
	writeData(FICHIER_VILLAGERS_SEARCH, villagersToSearch);
}

bool DataBase::addVillager(std::string nom) {
	int pos = searchCharacter(nom, availableCharacter);
	if (pos == -1 || villagers.size() == 10) {
		return false;
	}
	numberOfAvailableCharacterPerSpecie[availableCharacter[pos].getSpecie()] -= 1;
	villagers.push_back(availableCharacter[pos]);
	availableCharacter.erase(availableCharacter.begin() + pos);
	sortData();
	saveData();
	return true;
}

bool DataBase::deleteVillager(std::string nom){
	int pos = searchCharacter(nom, villagers);
	if (pos == -1) {
		return false;
	}
	numberOfAvailableCharacterPerSpecie[villagers[pos].getSpecie()] += 1;
	availableCharacter.push_back(villagers[pos]);
	villagers.erase(villagers.begin() + pos);
	sortData();
	saveData();
	return true;
}

bool DataBase::addVillagerToSearch(std::string nom){
	int pos = searchCharacter(nom, availableCharacter);
	if (pos == -1) {
		return false;
	}
	villagersToSearch.push_back(availableCharacter[pos]);
	sortData();
	saveData();
	return true;
}

bool DataBase::deleteVillagerToSearch(std::string nom){
	int pos = searchCharacter(nom, villagersToSearch);
	if (pos == -1) {
		return false;
	}
	villagersToSearch.erase(villagersToSearch.begin() + pos);
	sortData();
	saveData();
	return true;
}

void DataBase::printVillage() const {
	std::cout << "You have "<< villagers.size() << " Villagers in your island: ";
	for (size_t i = 0; i < villagers.size(); i++) {
		std::cout << villagers[i].getNom() << " ";
	}
	std::cout << std::endl;
}

void DataBase::printVillagerToSearch() const{
	std::cout << "Villagers that you are searching for: ";
	if (villagersToSearch.empty()) {
		std::cout << "You don't have any villager you are currently looking for" << std::endl;
	}
	else {
		for (size_t i = 0; i < villagersToSearch.size(); i++) {
			std::cout << villagersToSearch[i].getNom() << " ";
		}
		std::cout << std::endl;
	}
}

double DataBase::calculProbToGet(const std::string nom) const{
	int pos = searchCharacter(nom, villagersToSearch);
	if (pos == -1) {
		return 0.0;  
	}
	double probaRightSpecie = 1.0 / NUMBER_OF_SPECIES;
	double probaRightOneInSpecie = 1.0 / numberOfAvailableCharacterPerSpecie[villagersToSearch[pos].getSpecie()];  // = 1 / nbDeRacterePourCetteEspece
	return probaRightSpecie * probaRightOneInSpecie;
}

double DataBase::calculProbToGet(const std::vector<std::string> listNom, const int nbTry) const{
	double probaForSucces = 0.0;
	for (size_t i = 0; i < listNom.size(); i++){
		probaForSucces += calculProbToGet(listNom[i]);
	}
	double baseWithExponent = std::pow((1 - probaForSucces), nbTry);  //Loi géométrique x ~ G(probaForSucces)
	return 1 - baseWithExponent;   //Loi géométrique x ~ G(probaForSucces)
}

double DataBase::calculProbToGetAll(const int nbTry) const{
	double probaForSucces = 0.0;
	for (size_t i = 0; i < villagersToSearch.size(); i++) {
		probaForSucces += calculProbToGet(villagersToSearch[i].getNom());
	}
	double baseWithExponent = std::pow((1 - probaForSucces), nbTry);  //Loi géométrique x ~ G(probaForSucces)
	return 1 - baseWithExponent;   //Loi géométrique x ~ G(probaForSucces)
}

bool DataBase::isInSearchCharacter(std::string nom) const{
	for (size_t i = 0; i < villagersToSearch.size(); i++) {
		std::string nom1 = villagersToSearch[i].getNom();
		specieStr.toLowerCase(nom1);
		specieStr.toLowerCase(nom);
		if (nom1 == nom) {
			return true;
		}
	}
	return false;
}

bool DataBase::isMaxVillager(){
	return villagers.size() == 10;
}

void DataBase::readDataBase(){
	readFile(FICHIER_AVAILABLE_CHATACTER, availableCharacter);
	readFile(FICHIER_VILLAGERS, villagers);
	readFile(FICHIER_VILLAGERS_SEARCH, villagersToSearch);
}

void DataBase::readFile(const std::string fileName, std::vector<Character>& vector){
	std::ifstream file(fileName);
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> tabString = splitString(line);
		if (tabString.size() == 2) {
			Character character(tabString[0], specieStr.stringToEnum(tabString[1]));
			vector.push_back(character);
		}
	}
}

void DataBase::writeData(const std::string fileName, const std::vector<Character>& vector) const{
	std::ofstream file(fileName);
	for (size_t i = 0; i < vector.size(); i++) {
		file << vector[i].getNom() << " " << specieStr.enumToString(vector[i].getSpecie());
		if (i < vector.size() - 1 ) {
			file << std::endl;
		}
	}
}

void DataBase::initialiseLists(){
	for (size_t i = 0; i < availableCharacter.size();i++) {
		numberOfAvailableCharacterPerSpecie[(int)availableCharacter[i].getSpecie()] += 1;
	}
}

int DataBase::getNumberOfAvailableCharacterInSpecificSpecie(const Specie specie)const {
	return numberOfAvailableCharacterPerSpecie[(int)specie];
}

std::vector<std::string> DataBase::splitString(const std::string& string) const{
	std::vector<std::string> tabString;
	std::stringstream ss(string); // Turn the string into a stream. 
	std::string temp, delimiter = " ";
	for (std::string s; ss >> s; )
		tabString.push_back(s);

	return tabString;
}

int DataBase::searchCharacter(std::string nom, const std::vector<Character>& vector)const{
	specieStr.toLowerCase(nom);
	for (size_t i = 0; i < vector.size(); i++){
		std::string nomList = vector[i].getNom();
		specieStr.toLowerCase(nomList);
		if (nom == nomList) {
			return i;
		}
	}
	return -1;
}
bool compareSort(const Character& c1, const Character& c2){
	return (c1.getNom() < c2.getNom());
}
void DataBase::sortData(){
	std::sort(availableCharacter.begin(), availableCharacter.end(), compareSort);
	std::sort(villagers.begin(), villagers.end(), compareSort);
	std::sort(villagersToSearch.begin(), villagersToSearch.end(), compareSort);
}


