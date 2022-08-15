#include <iostream>
#include <fstream>
#include <string>

class Person
{
	std::string m_name;
	std::string m_surname;
	std::string m_data;
	std::string m_id;
	std::string m_number;
	std::string m_email;
public:
	void add_new_Contact();
	void list_all_Contact();
	void delete_a_Contact();
	void edit_a_Contact();
	void search_for_Contact();
};

void Person::add_new_Contact()
{
	std::cout << "Name: ";
	std::cin >> m_name;
	std::cout << "Surname: ";
	std::cin >> m_surname;
	std::cout << "Data: ";
	std::cin >> m_data;
	std::cout << "ID: ";
	std::cin >> m_id;
	std::cout << "Number: ";
	std::cin >> m_number;
	std::cout << "Email: ";
	std::cin >> m_email;

	std::ofstream cont("Contact_data.txt", std::ios::app);
	if(cont.is_open())
	{
		cont << m_email << " ";
		cont << m_name << " ";
		cont << m_surname << " ";
		cont << m_data << " ";
		cont << m_id << " ";
		cont << m_number << " ";
		cont << std::endl;
		
		cont.close();
	}
	else
	{
		std::cout << "The file could not be opened." << std::endl;
	}
	
	return;
}

void Person::list_all_Contact()
{
	std::string line;
	std::ifstream cont("Contact_data.txt");
	if(cont.is_open())
	{
		while(getline(cont, line))
		{	
			std::cout << std::endl;
			std::cout << "`````````````````````````````````````````````````" << std::endl;
			std::cout << " -->  " << line << std::endl;
		}
		cont.close();
	}
	else
	{
		std::cout << "The file could not be opened․" << std::endl;
	}

	return;
}

void Person::search_for_Contact()
{
	std::string email_fail;
	std::cout << "Enter email: ";
	std::cin >> m_email;
	std::string line;
	std::ifstream cont("Contact_data.txt");
	if(cont.is_open())
	{
		while(getline(cont, line))
		{
			int i = 0;
			email_fail = "";
			while(line[i] != ' ')
			{
				email_fail += line[i];
				++i;
			}
			if(m_email == email_fail)
			{
				//std::cout << line << std::endl;
				std::cout << m_email;
				for(int j = i; j < line.length(); ++j)
				{
					std::cout << line[j];
				}
				std::cout << std::endl;
			}
		}
		cont.close();
	}
	else
	{
		std::cout << "The file could not be opened․" << std::endl;
	}
	
	return;
}

void Person::delete_a_Contact()
{
	std::string line;
	std::string email_fail;
	std::cout << "Enter email: ";
	std::cin >> m_email;

	std::ifstream cont("Contact_data.txt");
	std::ofstream tmp;
	tmp.open("tmp.txt");
	if(cont.is_open())
	{
		while(getline(cont, line))
		{
			int i = 0;
			email_fail = "";
			while(line[i] != ' ')
			{
				email_fail += line[i];
				++i;
			}
			if(m_email != email_fail)
			{	
				//tmp << line << std::endl;
				std::cout << std::endl;
				tmp << email_fail;
				for(int j = i; j < line.length(); ++j)
				{
					tmp << line[j];			
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		tmp.close();
		cont.close();
		remove("Contact_data.txt");
		rename("tmp.txt", "Contact_data.txt");
	}	
	else
	{
		std::cout << "The file could not be opened." << std::endl;
	}

	return;
}

void Person::edit_a_Contact()
{
	std::cout << "Enter email: ";
	std::cin >> m_email;
	std::ifstream cont("Contact_data.txt");
	std::ofstream tmp;
	tmp.open("tmp.txt");

	std::string line;
	std::string email_fail = "";
	std::string name = "";
	std::string surname = "";
	std::string data = "";
	std::string id = "";
	std::string number = "";
	std::string change;

	std::cout << "Enter the data, you want to change: ";
	std::cin >> change;
	int i = 0;
	if(cont.is_open())
	{
		while(getline(cont, line))
		{
			//email_fail = "";
			while(line[i] != ' ')
			{
				email_fail += line[i];
				++i;
			}
			if(m_email == email_fail)
			{
				++i;
				while(line[i] != ' ')
				{
					name += line[i];
					++i;
				}
				++i;
				while(line[i] != ' ')
				{
					surname += line[i];
					++i;
				}
				++i;
				while(line[i] != ' ')
				{
					data += line[i];
					++i;
				}
				++i;
				while(line[i] != ' ')
				{
					id += line[i];
					++i;
				}
				++i;
				while(line[i] != ' ' || line[i] != (line.size() - 1))
				{
					number += line[i];
				}

				std::string data_change;
				std::cout << "Enter the new data: ";
				std::cin >> data_change;
				if(change == email_fail)
				{
					m_email = data_change;
				}
				if(change == name)
				{
					m_name = data_change;
				}
				if(change == surname)
				{
					m_surname = data_change;
				}
				if(change == data)
				{
					m_data = data_change;
				}
				if(change == id)
				{
					m_id = data_change;
				}
				if(change == number)
				{
					m_number = data_change;
				}
			}
		}
		cont.close();
	}
}

int main()
{
	Person per1;
	int num;
	do
	{	std::cout << "``````````````````````````" << std::endl;
		std::cout << "1. Add a new Contact" << std::endl;
		std::cout << "2. List all Contacts" << std::endl;
		std::cout << "3. Search for Contact" << std::endl;
		std::cout << "4. Edit a Contact" << std::endl;
		std::cout << "5. Delete a Contact" << std::endl;
		std::cout << "6. Exit" << std::endl;
		
		std::cout << "Enter a number(1-6): ";
		std::cin >> num;
		switch(num)
		{
			case 1:
				per1.add_new_Contact();
				break;
			case 2:
				per1.list_all_Contact();
				break;
			case 3:
				per1.search_for_Contact();
				break;
			case 4:
				per1.edit_a_Contact();
				break;
			case 5: 
				per1.delete_a_Contact();
				break;
			case 6:
				return 0;
				break;
		}
	}while(num != 6);

	return 0;
}















































