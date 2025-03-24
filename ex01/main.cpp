#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		phonebook.welcomeMessage();
		if (!std::getline(std::cin, command)) // Check for EOF
		{
			std::cout << GREEN << "🚪 EXIT" << RESET << std::endl;
			std::exit(0);
		}

		for (size_t j = 0; j < command.length(); j++) // if user's input is lowercase letter, make it uppercase
		{
			if (command[j] >= 97 && command[j] <= 122)
				command[j] = (char)toupper(command[j]);
		}

		if (command.compare("ADD") == 0)
		{
			std::cout << GREEN << "➕ ADD CONTACT" << RESET << std::endl;
			phonebook.addContact();
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << GREEN << "🔎 SEARCH CONTACT" << RESET << std::endl;
			phonebook.searchContacts();
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << GREEN << "🚪 EXIT" << RESET << std::endl;
			break;
		}
		else
		{
			std::cout << RED << "Invalid Command" << RESET << std::endl;
			std::cout << RED << "Only ADD, SEARCH and EXIT Commands are allowed" << RESET << std::endl;
		}
	}
	return (0);
}
