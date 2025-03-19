#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Welcome to PhoneBook Program" << std::endl;
		std::cout << "This Program Only Accept: ADD, SEARCH and EXIT" << std::endl;
		std::cout << "Please type in your command" << std::endl;

		std::getline(std::cin, command);

		if (command.compare("ADD") == 0)
		{
			std::cout << "ADDING A CONTACT TO PHONEBOOK" << std::endl;
			phonebook.addContact();
		}

		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "SEARCHING" << std::endl;
			// phonebook.searchContacts();
		}

		else if (command.compare("EXIT") == 0)
		{
			std::cout << "EXITING" << std::endl;
			break;
		}
	}
}