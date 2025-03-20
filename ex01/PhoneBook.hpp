#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

class PhoneBook
{
	private:
		Contact contacts[8];
		int num_Contacts;
		int	i;

		std::string replace_dot(std::string str);
		void print_table_header();
		void print_contact_in_table();
		void prompt_display_contact();
		
	public:
		PhoneBook();
		void addContact();
		void searchContacts();
		void displayContact(int index);
};

#endif