#include <map>
#include <iostream>
#include <string>

int main(){
	std::map<std::string, float> db;

	db["2011-01-03"]= 0.30;
	db["2012-01-11"]= 7.10;
	db["2013-06-15"]= 100.0;

	std::cout << db["2012-01-11"] << std::endl;

	for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
	{
		std::cout << it->first <<"="<< it->second << std::endl;
	}

}
