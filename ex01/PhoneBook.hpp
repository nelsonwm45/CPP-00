#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits> // for max()

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
		int	maxContacts;
		int	i;

		Contact add_contact_info(std::string info[5]);
		void getContactInfo(std::string (&info)[5]);
		int invalid_response(std::string info);

		void print_table_header();
		void print_contact_in_table();

		std::string replace_dot(std::string str);
		
	public:
		PhoneBook();
		void welcomeMessage();
		void addContact();
		void searchContacts();
		void prompt_display_contact();
		void displayContact(int index);
};

#endif