#pragma once
#include<string>
#include<iostream>

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

	const std::string& getFirstName() const;
	const std::string& getMiddleName() const;
	const std::string& getLastName() const;

	void printName() const;

};

