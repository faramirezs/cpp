#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void loadCSV(const std::string & filename, std::map<std::string, float> &db){
	std::ifstream file(filename.c_str());
	if(!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while(std::getline(file, line)){
		std::istringstream ss(line); //treat every
		std::string date, rateStr;

		if(std::getline(ss, date, ',') && std::getline(ss, rateStr)){
			float rate = static_cast<float>(std::atof(rateStr.c_str()));
			db[date] = rate;
		}

	}
}




int main(int ac, char** av){

	if (ac != 2){
		std::cerr << "Error: no file" << std::endl;
		return 1;
	}

	std::map<std::string, float> db;
	loadCSV(*av, db);

	db["2011-01-03"]= 0.30;
	db["2012-01-11"]= 7.10;
	db["2013-06-15"]= 100.0;

	std::cout << db["2012-01-11"] << std::endl;

	for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
	{
		std::cout << it->first <<"="<< it->second << std::endl;
	}
}
