#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int totalContacts;
	
	public:
		PhoneBook();
		void addContact();
		void searchContacts();
		void displayContact(int index);
};

#endif