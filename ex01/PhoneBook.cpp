# include "PhoneBook.hpp"

// Default Constructor
PhoneBook::PhoneBook() {};

void	PhoneBook::addContact()
{
	Contact	newContact;
	std::string	line;
	static int	i = 0;

	std::cout << "First Name: ";
	std::getline(std::cin, line);
	newContact.setFirstName(line);

	std::cout << "Last Name: ";
	std::getline(std::cin, line);
	newContact.setLastName(line);

	std::cout << "Nickname: ";
	std::getline(std::cin, line);
	newContact.setNickname(line);

	std::cout << "Phone Number: ";
	std::getline(std::cin, line);
	newContact.setPhoneNumber(line);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, line);
	newContact.setDarkestSecret(line);

	this->contacts[i] = newContact;
	totalContacts++;
	i++;
	if (totalContacts == 8)
	
};