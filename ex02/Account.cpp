/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:34:16 by mhummel           #+#    #+#             */
/*   Updated: 2024/11/21 11:04:35 by mhummel          ###   ########.fr       */
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
