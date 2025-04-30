#include "Account.hpp"
# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <ctime>
#include <vector>
#include <algorithm>
#include <functional>

//int deposit;
//int initial_deposit;

//void Account::dis

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
    //[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
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
    //[19920104_091532] index:0;p_amount:47;withdrawal:refused
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
        << ";amount" << Account::_amount
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

/* int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
} */