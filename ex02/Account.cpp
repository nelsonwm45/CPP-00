#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip> // for std::put_time

/*
	@ These variables are shared among all instances of Account
	@ only one copy of these variables in memory, no matter how many Account objects you create.

	_nbAccounts keeps track of the total number of accounts.
	_totalAmount stores the sum of all balances in every Account object.
	_totalNbDeposits stores total number of deposits in all accounts.
	_totalNbWithdrawals stores total number of withdrawals in all accounts.

	Initialise every static variables to 0;
*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
	Constructor
	1. build account and initialise its value
	2. update staic class variable (nb of accounts and total amounts)
	3. print logs

	No deposit and withdrawals were made during account creation

*/
Account::Account (int initial_deposit)
{
	// Build and initialise value
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// Update Static Class Variable
	_nbAccounts++;
	_totalAmount += initial_deposit;

	// Prints Logs
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

/*
	Destructor
	[19920104_091532] index:0;amount:47;closed
*/
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;

	// Update the NbAccount
	_nbAccounts--;
}

/*
	Based on log: [19920104_091532] in format of [YYYYMMDD_HHMMSS]
	std::time https://en.cppreference.com/w/cpp/chrono/c/time
	
	
	std::tm https://en.cppreference.com/w/cpp/chrono/c/tm#:~:text=struct%20tm%3B,broken%20down%20into%20its%20components.
	tm_year --- years since 1900 (public member object)

	std::tm is a struct
	struct std::tm {
	int tm_sec;   // Seconds (0-59)
	int tm_min;   // Minutes (0-59)
	int tm_hour;  // Hours (0-23)
	int tm_mday;  // Day of the month (1-31)
	int tm_mon;   // Month (0-11) [January = 0, December = 11]
	int tm_year;  // Years since 1900 (e.g., 2025 is stored as 125)
	int tm_wday;  // Day of the week (0-6) [Sunday = 0, Saturday = 6]
	int tm_yday;  // Day of the year (0-365)
	int tm_isdst; // Daylight Saving Time flag (1 = Yes, 0 = No)

	std::localtime() will takes in a pointer of and return a pointer
};

*/
void	Account::_displayTimestamp()
{
	std::time_t t;  // Declares a variable 't' to store time in seconds
	std::tm	*current;
	char	buffer[20];

	std::time(&t); // retrieve the current time in seconds since 1970
	current = std::localtime(&t); // convert to local time
	
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", current); // convert to string from current tm
	std::cout << buffer; // print the formatted time
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/*
	logs : [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

	Basically trying to display TOTAL ACCOUNT STATUS
*/
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

/*
	logfile
	[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
	[19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
	[19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
	[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
	[19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
	[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
	[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1

*/
void	Account::makeDeposit( int deposit )
{
	int	old_amount;
	
	old_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << old_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

/*
	logfile:
	[19920104_091532] index:0;p_amount:47;withdrawal:refused
	[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	[19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
	[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
	[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
	[19920104_091532] index:5;p_amount:23;withdrawal:refused
	[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
	[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
*/
bool	Account::makeWithdrawal( int withdrawal )
{
	int	old_amount;

	old_amount = this->_amount;
	if (withdrawal > old_amount)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << old_amount
				  << ";withdrawal:refused"
				  << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << old_amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_deposits:" << this->_nbWithdrawals
				  << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

/*
	logfiles
	[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
	[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
	[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
	[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
	[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
	[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
	[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0

	Basically trying to display each accounts status
*/
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}
