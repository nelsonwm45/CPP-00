# include "PhoneBook.hpp"

// Default Constructor
PhoneBook::PhoneBook()
{
	this->num_Contacts = 0;
	this->i = 0;
	this->maxContacts = 0;
}

void	PhoneBook::welcomeMessage()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Welcome to PhoneBook Program" << RESET << std::endl;
	std::cout << GREEN << "This Program Only Accept: " << BLUE << "➕ ADD, 🔎 SEARCH and 🚪 EXIT" << RESET << std::endl;
	std::cout << GREEN << "Please type in your command" << RESET << std::endl;
	std::cout << BLUE << "Command > " << RESET;
}

Contact	PhoneBook::add_contact_info(std::string info[5])
{
	Contact newContact;

	newContact.setFirstName(info[0]);
	newContact.setLastName(info[1]);
	newContact.setNickname(info[2]);
	newContact.setPhoneNumber(info[3]);
	newContact.setDarkestSecret(info[4]);
	return (newContact);
}

int	PhoneBook::invalid_response(std::string info)
{
	if (info.empty() == true)
		return (0);
	
	// Check if the string consists only of spaces or tabs
	for (size_t j = 0; j < info.length(); j++)
	{
		if (info[j] != ' ' && info[j] != '\t') // Found a valid character
			return (1);
	}

	return (0); // Found spaces or tabs
}

void	PhoneBook::getContactInfo(std::string (&info)[5])
{
	std::string	prompts[] = {
		"First Name: ",
		"Last Name: ",
		"Nickname: ",
		"Phone Number: ",
		"Darkest Secret: "
	};

	for (int k = 0; k < 5; k++)
	{
		std::cout << BLUE << prompts[k] << RESET;
		std::getline(std::cin, info[k]);
		if (invalid_response(info[k]) == 0)
		{
			std::cout << RED << "Empty value/Invalid Response" << RESET << std::endl;
			k--;
		}
	}
}

void	PhoneBook::addContact()
{
	Contact	newContact;
	std::string	info[5];
	
	getContactInfo(info);
	newContact = add_contact_info(info);

	i = num_Contacts % 8;
	this->contacts[i] = newContact;
	num_Contacts++;
	if (maxContacts < 8)
		maxContacts++;
	std::cout << "✅ Contact added successfully!" << std::endl;
}

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
	for (int j = 0; j < maxContacts; j++)
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
	std::cout << BLUE << "Please enter the index of contact you wish to display: " << RESET;
	std::cin >> i; // Only read for number, causing newline is not read

	if (std::cin.fail())  // Handle non-integer input
	{
		std::cin.clear();  // Clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Remove bad input
		std::cout << RED << "Invalid index, please enter a number." << RESET << std::endl;
		return ;
	}
	if (i >= 0 && i < maxContacts)
		displayContact(i);
	else
		std::cout << RED << "Index out of range" << RESET << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover newline
}

void	PhoneBook::searchContacts()
{
	if (num_Contacts == 0)
	{
		std::cout << CYAN << "There is no contact in PhoneBook yet!" << RESET << std::endl;
		std::cout << CYAN << "Please proceed to add some" << RESET << std::endl;
	}
	else
	{
		print_table_header();
		print_contact_in_table();
		prompt_display_contact();
	}
};


void	PhoneBook::displayContact(int index)
{
	std::cout << YELLOW << "First Name: " << BLUE << contacts[index].getFirstName() << RESET << std::endl;
	std::cout << YELLOW << "Last Name: " << BLUE << contacts[index].getLastName() << RESET << std::endl;
	std::cout << YELLOW << "Nickname: " << BLUE << contacts[index].getNickname() << RESET << std::endl;
	std::cout << YELLOW << "Phone Number: " << BLUE << contacts[index].getPhoneNumber() << RESET << std::endl;
	std::cout << YELLOW << "Darkest Secret: " << BLUE << contacts[index].getDarkestSecret() << RESET << std::endl;
}
