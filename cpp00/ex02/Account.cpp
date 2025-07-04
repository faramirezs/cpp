/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:38:14 by alramire          #+#    #+#             */
/*   Updated: 2025/07/04 14:45:26 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <ctime>
# include <vector>
# include <algorithm>
# include <functional>

//c++ -Wall -Wextra -Werror -std=c++98 Account.cpp Account.hpp tests.cpp

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp (void)
{
    time_t timestamp;
    char output[19];
    struct tm * datetime;

    time(&timestamp);
    datetime = localtime(&timestamp);

    strftime(output, 19, "[%Y%m%d_%H%M%S] ", datetime);
    std::cout << output;
}

void Account::displayAccountsInfos (void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts 
        << ";total:" << Account::_totalAmount
        << ";deposits:" << Account::_totalNbDeposits
        << ";withdrawls:" << Account::_totalNbWithdrawals
        << "\n";
};

void Account::makeDeposit(int deposit)
{
    Account::_totalAmount = Account::_totalAmount + deposit;
    Account::_amount = Account::_amount + deposit;
    Account::_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex 
        << ";p_amount:" << Account::_amount - deposit
        << ";deposit:" << deposit
        << ";amount:" << Account::_amount
        << ";nb_deposits:" << Account::_nbDeposits
        << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    if(withdrawal <= Account::_amount)
    {
        Account::_totalAmount = Account::_totalAmount - withdrawal;
        Account::_amount = Account::_amount - withdrawal;
        Account::_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        Account::_displayTimestamp();
        std::cout << "index:" << Account::_accountIndex 
            << ";p_amount:" << Account::_amount + withdrawal
            << ";withdrawal:" << withdrawal
            << ";amount:" << Account::_amount
            << ";nb_withdrawals:" << Account::_nbWithdrawals
            << "\n";
        return (true);
    }
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex 
            << ";p_amount:" << Account::_amount
            << ";withdrawal:" << "refused"
            << "\n";
    return (false);
}

Account::Account(int initial_deposit)
{
    Account::_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_amount = initial_deposit;
    Account::_totalAmount = Account::_totalAmount + initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex
        << ";amount:" << Account::_amount
        << ";created"
        << "\n";
}

void Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex 
        << ";amount:" << Account::_amount
        << ";deposits:" << Account::_nbDeposits
        << ";withdrawls:" << Account::_nbWithdrawals
        << "\n";
};

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex
        << ";amount:" << Account::_amount
        << ";closed"
        << "\n";
}

/* int	Account::getNbAccounts( void )
{
    void;
}
int	Account::getTotalAmount( void )
{
    void;
}
int	Account::getNbDeposits( void )
{
    void;
}
int	Account::getNbWithdrawals( void )
{
    void;
} */

/* void Account::makeDeposit(deposit)
{

} */