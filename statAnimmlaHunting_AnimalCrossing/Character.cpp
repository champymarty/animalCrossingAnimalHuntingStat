#include "Character.h"

Character::Character(std::string nom, Specie specie){
    this->nom = nom;
    this->specie = specie;
}

Character::Character(std::string nom, std::string specie){
}

Character::Character(){
}

std::string Character::getNom() const {
    return nom;
}

Specie Character::getSpecie() const {
    return specie;
}

std::ostream& operator<<(std::ostream& outputStream, const Character& character){
    return outputStream << character.nom << " " << character.specie;
}
