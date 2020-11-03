#include "Vue.h"

void Vue::start(){
	data.printVillage();
	std::cout << std::endl;
	data.printVillagerToSearch();
	std::cout << std::endl << help << std::endl;
	listening();
}

void Vue::listening(){
	std::string command;
	std::getline(std::cin, command);
	std::vector<std::string> commandVector = splitString(command);
	processCommand(commandVector);
}

void Vue::processCommand(std::vector<std::string> commands) {
	if (commands.size() == 1) {
		if (commands[0] == "quit") {
			exit(0);
		}else if (commands[0] == "clear") {
			system("cls");
		}
		else if (commands[0] == "help") {
			std::cout << std::endl << help << std::endl;
		}
		else {
			invalidCommand();
		}
	}else if (commands.size() == 2) {
		if (commands[0] == "show") {
			commandShow(commands);
		}else {
			invalidCommand();
		}
	}else if (commands.size() == 3) {
		if (commands[0] == "add") {
			commandAdd(commands);
		}else if (commands[0] == "remove") {
			commandRemove(commands);
		}else {
			invalidCommand();
		}
	}else {
		invalidCommand();
	}

	listening();
}

std::vector<std::string> Vue::splitString(const std::string& string) const{
	std::vector<std::string> tabString;
	std::stringstream ss(string); // Turn the string into a stream. 
	std::string temp, delimiter = " ";
	for (std::string s; ss >> s; )
		tabString.push_back(s);

	return tabString;
}

void Vue::invalidCommand() const{
	std::cout << "La commande est invalide" << std::endl;
}

void Vue::commandAdd(std::vector<std::string> commands){
	if (commands[1] == "village") {
		for (size_t i = 2; i < commands.size(); i++) {
			bool add = data.addVillager(commands[i]);
			if (add) {
				std::cout << "The villager " << commands[i] << " has bean hadded to your village" << std::endl;
			}
			else {
				std::cout << "The villager " << commands[i] << " does not exist" << std::endl;
			}
		}
	}
	else if (commands[1] == "search") {
		for (size_t i = 2; i < commands.size(); i++) {
			bool add = data.addVillagerToSearch(commands[i]);
			if (add) {
				std::cout << "The villager " << commands[i] << " has bean hadded to your wanted villager" << std::endl;
			}
			else {
				std::cout << "The villager " << commands[i] << " does not exist" << std::endl;
			}
		}
	}
	else {
		invalidCommand();
	}
}

void Vue::commandRemove(std::vector<std::string> commands){
	if (commands[1] == "village") {
		for (size_t i = 2; i < commands.size(); i++) {
			bool add = data.deleteVillager(commands[i]);
			if (add) {
				std::cout << "The villager " << commands[i] << " has bean remove of your villagers" << std::endl;
			}
			else {
				std::cout << "The villager " << commands[i] << " does not exist in your villagers" << std::endl;
			}
		}
	}
	else if (commands[1] == "search") {
		for (size_t i = 2; i < commands.size(); i++) {
			bool add = data.deleteVillagerToSearch(commands[i]);
			if (add) {
				std::cout << "The villager " << commands[i] << " has bean remove of your wanted village" << std::endl;
			}
			else {
				std::cout << "The villager " << commands[i] << " does not exist in your watned villagers" << std::endl;
			}
		}
	}
	else {
		invalidCommand();
	}
}

void Vue::commandShow(std::vector<std::string> commands){
	if (commands[1] == "village") {
		data.printVillage();
	}
	else if (commands[1] == "search") {
		data.printVillagerToSearch();
	}
}
