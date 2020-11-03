#include "SpecieString.h"

SpecieString::SpecieString(){
	umap["ALLIGATOR"] = Specie::ALLIGATOR;
	umap["ANTEATER"] = Specie::ANTEATER;
	umap["BEAR"] = Specie::BEAR;
	umap["BIRD"] = Specie::BIRD;
	umap["BULL"] = Specie::BULL;
	umap["CAT"] = Specie::CAT;
	umap["CHICKEN"] = Specie::CHICKEN;
	umap["COW"] = Specie::COW;
	umap["CUB"] = Specie::CUB;
	umap["DEER"] = Specie::DEER;
	umap["DOG"] = Specie::DOG;
	umap["DUCK"] = Specie::DUCK;
	umap["EAGLE"] = Specie::EAGLE;
	umap["ELEPHANT"] = Specie::ELEPHANT;
	umap["FROG"] = Specie::FROG;
	umap["GOAT"] = Specie::GOAT;
	umap["GORILLA"] = Specie::GORILLA;
	umap["HAMSTER"] = Specie::HAMSTER;
	umap["HIPPO"] = Specie::HIPPO;
	umap["HORSE"] = Specie::HORSE;
	umap["KANGAROO"] = Specie::KANGAROO;
	umap["KOALA"] = Specie::KOALA;
	umap["LION"] = Specie::LION;
	umap["MONKEY"] = Specie::MONKEY;
	umap["MOUSE"] = Specie::MOUSE;
	umap["OCTOPUS"] = Specie::OCTOPUS;
	umap["OSTRICH"] = Specie::OSTRICH;
	umap["PENGUIN"] = Specie::PENGUIN;
	umap["PIG"] = Specie::PIG;
	umap["RABBIT"] = Specie::RABBIT;
	umap["RHINO"] = Specie::RHINO;
	umap["SHEEP"] = Specie::SHEEP;
	umap["SQUIRREL"] = Specie::SQUIRREL;
	umap["TIGER"] = Specie::TIGER;
	umap["WOLF"] = Specie::WOLF;
}
Specie SpecieString::stringToEnum(std::string string) const{
	toUpperCase(string);
	auto itr = umap.find(string);
	if (itr == umap.end())
		return Specie::EMPTY;
	else
		return itr->second;
}

std::string SpecieString::enumToString(const Specie specie) const{
	std::string returnStr = "";
	for (auto itr = umap.begin(); itr != umap.end(); itr++){
		if (itr->second == specie) {
			returnStr = itr->first;
			break;
		}
	}
	if (returnStr == "") {
		return returnStr;
	}
	toLowerCase(returnStr);
	returnStr[0] = std::toupper(returnStr[0]);
	return returnStr;
}

void SpecieString::toLowerCase(std::string& string) const {
	for (size_t i = 0; i < string.size(); i++) {
		char c = string[i];
		if (isalpha(c)) {
			string[i] = std::tolower(c);
		}
	}
}

void SpecieString::toUpperCase(std::string& string) const{
	for (size_t i = 0; i < string.size(); i++) {
		char c = string[i];
		if (isalpha(c)) {
			string[i] = std::toupper(c);
		}
	}
}
