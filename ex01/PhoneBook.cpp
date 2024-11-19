/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/11/17 16:36:06 by mhummel          ###   ########.fr       */
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
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->contactCount; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContact() const {
	int index;

	this->displayContact();
	std::cout << "Enter the index of the contact you would like to view: ";
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index >= this->contactCount) {
		std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return;
	}

	std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}
