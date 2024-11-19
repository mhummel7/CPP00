/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:28:31 by mhummel           #+#    #+#             */
/*   Updated: 2024/11/17 16:30:22 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(std::string name) {
	this->firstName = name;
}

void Contact::setLastName(std::string name) {
	this->lastName = name;
}

void Contact::setNickname(std::string nick) {
	this->nickname = nick;
}

void Contact::setPhoneNumber(std::string number) {
	this->phoneNumber = number;
}

void Contact::setDarkestSecret(std::string secret) {
	this->darkestSecret = secret;
}

std::string Contact::getFirstName() const {
	return this->firstName;
}

std::string Contact::getLastName() const {
	return this->lastName;
}

std::string Contact::getNickname() const {
	return this->nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->darkestSecret;
}
