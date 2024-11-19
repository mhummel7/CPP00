/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/11/19 12:57:24 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	this->contactCount = 0;
	this->oldestContact = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact contact) {
	if (this->contactCount < 8) {
		this->contacts[this->contactCount] = contact;
		this->contactCount++;
	}
	else {
		this->contacts[this->oldestContact] = contact;
		this->oldestContact = (this->oldestContact + 1) % 8;
	}
}

std::string truncate(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::displayContact() const {
	std::cout << "\n○-------------------------------------------○" << std::endl;
	std::cout << "|" << MAGENTA << std::setw(10) << "Index  " << RESET << "|";
	std::cout << GREEN << std::setw(10) << "FirstName" << RESET << "|";
	std::cout << BLUE << std::setw(10) << "LastName " << RESET << "|";
	std::cout << YELLOW << std::setw(10) << "Nickname " << RESET << "|" << std::endl;
	std::cout << "○-------------------------------------------○" << std::endl;
	for (int i = 0; i < this->contactCount; i++) {
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "○-------------------------------------------○" << std::endl;
	std::cout <<"\n" << std::endl;
}

void PhoneBook::searchContact() const {
	int index;

	this->displayContact();
	std::cout << "Enter the \033[35mindex\033[0m of the contact you would like to view: ";
	std::cin >> index;
	std::cin.ignore(10000, '\n');

	if (std::cin.fail() || index < 0 || index >= this->contactCount) {
		std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return;
	}

	std::cout << GREEN << "First Name: " << RESET << this->contacts[index].getFirstName() << std::endl;
	std::cout << BLUE << "Last Name: " << RESET << this->contacts[index].getLastName() << std::endl;
	std::cout << YELLOW << "Nickname: " << RESET << this->contacts[index].getNickname() << std::endl;
	std::cout << CYAN << "Phone Number: " << RESET << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << RED << "Darkest Secret: " << RESET << this->contacts[index].getDarkestSecret() << "\n" << std::endl;
}
