#include "Account.hpp"
# include <string>
# include <iostream>
# include <limits>
# include <iomanip>

//int deposit;
//int initial_deposit;

void Account::displayAccountsInfos (void)
{
    std::cout << "index:" << Account::_nbAccounts 
        << "amount:" << Account::_totalAmount
        << "deposits:" << Account::_totalNbDeposits
        << "withdrawls" << Account::getNbWithdrawals;
};

Account(int initial_deposit)
{
    Account
}


/* void Account::makeDeposit(deposit)
{

} */