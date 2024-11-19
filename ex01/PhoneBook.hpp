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

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define RESET	"\033[0m"

#endif
