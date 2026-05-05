# include "BitcoinExchange.hpp"

bool isValidAmount(const std::string& amountStr){
	if (amountStr.empty())
		return false;
	bool decimal = false;
	for (size_t i = 0; i < amountStr.length(); i++)
	{
		if (i==0 && amountStr[i] == '-')
			continue;
		if (amountStr[i] == '.'){
			if (decimal == false)
				decimal = true;
			else
				return false;
			continue;
		}
		if(!isdigit(amountStr[i]))
			return false;
	}
	if (amountStr == "." || amountStr == "-")
		return false;
	return true;
}

bool isValidDate(const std::string& date){

	if (date.length() != 10)
		return false;
	if ( date[4] != '-')
		return false;
	if ( date[7] != '-')
		return false;
	for (size_t i = 0; i < 10; i++)
	{
		if (i ==4 || i ==7)
			continue;
		if(!(isdigit(date[i])))
			return false;
	}
	int year, month, day;
	year = atoi(date.substr(0,4).c_str());
	month = atoi(date.substr(5,2).c_str());
	day = atoi(date.substr(8,2).c_str());
	if(!(month>= 1 && month <=12 ))
		return false;
	if(!(day >= 1 && day <=31 ))
		return false;
	if(date < "2009-01-02")
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeap)
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

int main(int ac, char** av){

	if (ac != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream file(av[1]);
	if(!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	std::string line;
	std::getline(file, line);

	while(std::getline(file, line)){
		std::istringstream ss(line);
		std::string date,separator, amountStr;

		if (ss >> date >> separator >> amountStr && separator == "|") {
			float amount = static_cast<float>(std::atof(amountStr.c_str()));

			if(!(isValidDate(date)) || !(isValidAmount(amountStr))){
				if(!(isValidDate(date)))
					std::cerr << "Error: bad input => " << date << std::endl;
				else if(!(isValidAmount(amountStr)))
					std::cerr << "Error: bad input => " << amountStr << std::endl;
			}
			else
				if (amount < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else
					if (amount > 1000)
						std::cerr << "Error: too large a number." << std::endl;
					else
						std::cout << date << " => " << amount << " = " << amount * btc.getRate(date) << std::endl;
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}
