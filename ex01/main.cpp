/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:36:12 by mhummel           #+#    #+#             */
/*   Updated: 2024/11/19 12:54:55 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

Contact createContact() {
	Contact contact;
	std::string input;

	std::cout << "Enter \033[32mfirst name:\033[0m ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << "Enter \033[34mlast name:\033[0m ";
	std::getline(std::cin, input);
	contact.setLastName(input);

	std::cout << "Enter \033[33mnickname:\033[0m ";
	std::getline(std::cin, input);
	contact.setNickname(input);

	std::cout << "Enter \033[36mphone number:\033[0m ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);

	std::cout << "Enter \033[31mdarkest secret:\033[0m ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);

	return contact;
}

int main() {
	PhoneBook phoneBook;
	std::string input;

	while (true) {
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n";
			exit(1);
		}
		if (input == "ADD") {
			phoneBook.addContact(createContact());
		}
		else if (input == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (input == "EXIT") {
			break;
		}
	}
	return 0;
}
