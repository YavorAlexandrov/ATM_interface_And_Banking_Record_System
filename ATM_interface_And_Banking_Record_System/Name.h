#pragma once
#include<string>

class Name
{
	std::string firstName;
	std::string middleName;
	std::string lastName;

public:
	Name();
	Name(const std::string& fName, const std::string& mName, const std::string& lName);
	
	void setFirstName(const std::string& fName);
	void setMiddleName(const std::string& mName);
	void setLastName(const std::string& lName);

	const std::string& getFirstName();
	const std::string& getMiddleName();
	const std::string& getLastName();

	void printName();

};

