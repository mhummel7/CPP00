#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;
	int oldestContact;

public:
	PhoneBook();
	~PhoneBook();

	void addContact(Contact contact);
	void searchContact() const;
	void displayContact() const;
};

#endif
