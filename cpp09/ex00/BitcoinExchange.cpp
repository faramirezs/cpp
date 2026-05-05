# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	loadCSV();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : db(other.db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this == &other)
    	return *this;
	db = other.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadCSV(){
	std::ifstream file(DB_DATA);
	if(!file.is_open()) {
		std::cerr << "Error: could not open db file" << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while(std::getline(file, line)){
		std::istringstream ss(line);
		std::string date, rateStr;

		if(std::getline(ss, date, ',') && std::getline(ss, rateStr)){
			float rate = static_cast<float>(std::atof(rateStr.c_str()));
			db[date] = rate;
		}
	}
}

float BitcoinExchange::getRate(std::string date){
	if (db.empty())
		return 0.0f;
	std::map<std::string, float>::iterator it = db.lower_bound(date);
	if (it == db.end()) {
		--it;
	} else if (it->first != date) {
		if (it == db.begin())
			return it->second;
		--it;
	}
	return it->second;
}
