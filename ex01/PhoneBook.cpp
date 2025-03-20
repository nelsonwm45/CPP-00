# include "PhoneBook.hpp"

// Default Constructor
PhoneBook::PhoneBook()
{
	this->num_Contacts = 0;
	this->i = 0;
};

void	PhoneBook::addContact()
{
	Contact	newContact;
	std::string	line;

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

	i = num_Contacts % 8;
	this->contacts[i] = newContact;
	num_Contacts++;
	std::cout << "Contact added successfully!" << std::endl;
	std::cout << "Total Contacts: " << num_Contacts<< std::endl;
};


void	PhoneBook::print_table_header()
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|";
	std::cout << std::endl;
}

std::string	PhoneBook::replace_dot(std::string str)
{
	std::string	new_str;

	if (str.length() > 10)
	{
		new_str = str.substr(0, 9);
		new_str.append(".");
		return (new_str);
	}
	return (str);
}
void	PhoneBook::print_contact_in_table()
{
	for (int j = 0; j < num_Contacts; j++)
	{
		std::cout << std::setw(10) << std::right << j << "|";
		std::cout << std::setw(10) << std::right << replace_dot(contacts[j].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << replace_dot(contacts[j].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << replace_dot(contacts[j].getNickname()) << "|";
		std::cout << std::endl;
	}
}

void	PhoneBook::prompt_display_contact()
{
	std::cout << "Please enter the index of contact you wish to display: ";
	std::cin >> i;
	if (i >= 0 && i < num_Contacts)
		displayContact(i);
	else
		std::cout << "Index out of range" << std::endl;

}
void	PhoneBook::searchContacts()
{
	if (num_Contacts == 0)
	{
		std::cout << "There is no contact in PhoneBook yet!" << std::endl;
		std::cout << "Please proceed to add some" << std::endl;
	}
	else
	{
		print_table_header();
		print_contact_in_table();
		prompt_display_contact();
	}
};


// void PhoneBook::searchContacts()
// {
// 	if (totalContacts == 0)
// 	{
// 		std::cout << "There is no contact in PhoneBook yet!" << std::endl;
// 		std::cout << "Please proceed to add some" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << std::setw(10) << "Index" << "|";
// 		std::cout << std::setw(10) << "First Name" << "|";
// 		std::cout << std::setw(10) << "Last Name" << "|";
// 		std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
// 		for (int j = 0; j < totalContacts; j++)
// 		{
// 			std::cout << std::setw(10) << j << "|";
// 			std::cout << std::setw(10) << contacts[j].getFirstName() << "|";
// 			std::cout << std::setw(10) << contacts[j].getLastName() << "|";
// 			std::cout << std::setw(10) << contacts[j].getNickname() << "|" << std::endl;
// 		}
// 		std::cout << "Please enter the index of the contact you want to display" << std::endl;
// 		std::cin >> i;
// 		if (i >= 0 && i < totalContacts)
// 			displayContact(i);
// 		else
// 			std::cout << "Invalid Index" << std::endl;
// 	}
// }

void	PhoneBook::displayContact(int index)
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
};