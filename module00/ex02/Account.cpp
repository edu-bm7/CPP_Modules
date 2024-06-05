#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		  << "p_amount:" << _amount << ";"
		  << "deposit:" << deposit << ";"
		  << "amount:" << _amount + deposit << ";"
		  << "nb_deposits:" << _nbDeposits + 1 << std::endl;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount >= withdrawal) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount - withdrawal << ";"
			  << "nb_withdrawals:" << _nbWithdrawals + 1
			  << std::endl;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	} else {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "withdrawal:" << "refused" << std::endl;
		return false;
	}
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t t = std::time(NULL);
    struct tm* currentTime = std::localtime(&t);
	
	std::cout << "[";
    std::cout << std::setfill('0')
              << std::setw(4) << currentTime->tm_year + 1900
              << std::setw(2) << currentTime->tm_mon + 1
              << std::setw(2) << currentTime->tm_mday
              << "_"
              << std::setw(2) << currentTime->tm_hour
              << std::setw(2) << currentTime->tm_min
              << std::setw(2) << currentTime->tm_sec;
	std::cout << "] ";
}
