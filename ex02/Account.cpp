/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:34:16 by mhummel           #+#    #+#             */
/*   Updated: 2024/11/21 11:14:23 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

// Initialize static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Display Timestamp
void Account::_displayTimestamp(void)
{
	time_t now = time(nullptr);
	struct tm *ltm = localtime(&now);

	std::cout	<< "[" << std::setfill('0')
				<< std::setw(4) << 1900 + ltm->tm_year
				<< std::setw(2) << 1 + ltm->tm_mon
				<< std::setw(2) << ltm->tm_mday
				<< "_"
				<< std::setw(2) << ltm->tm_hour
				<< std::setw(2) << ltm->tm_min
				<< std::setw(2) << ltm->tm_sec
				<< "] ";
}

// Konstruktor
Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

// Destruktor
Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

// Getter
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// Deposit
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

// Withdrawal
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";

	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout	<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}


// Check Account amount
int Account::checkAmount(void) const
{
	return (_amount);
}
