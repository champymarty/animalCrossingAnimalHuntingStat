#ifndef VUE_H
#define VUE_H

#include "DataBase.h"

class Vue{
public:
	void start();
	void listening();
	void processCommand(std::vector<std::string> commands);
private:
	DataBase data;
	const std::string help = "Commands:\n	show village/search \n	add/remove village/search name1 name2 name3 ... \n	help \n	clear \n	quit";

	std::vector<std::string> splitString(const std::string& string)const;
	void invalidCommand()const;
	void commandAdd(std::vector<std::string> commands);
	void commandRemove(std::vector<std::string> commands);
	void commandShow(std::vector<std::string> commands);
};
#endif

