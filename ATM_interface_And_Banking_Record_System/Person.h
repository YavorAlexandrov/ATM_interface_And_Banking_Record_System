#pragma once
#include<string>
#include"Name.h"
#include"Date.h"
class Person
{

	std::string EGN;
	Name fullName;
	Date date;
	std::string phoneNum;
	std::string address;

public:
	Person();
	Person(const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address);
	virtual ~Person();


	void setEGN(const std::string EGN);
	void setName(const Name& name);
	void setDate(const Date& date);
	void setPhone(const std::string phone);
	void setAddress(const std::string address);

	//void printPerson();


	const std::string& getUsername();
	const std::string& getPassword();
	const std::string& getEGN();
	const Name& getName();
	const Date& getDate();
	const std::string& getPhone();
	const std::string& getAddress();

	virtual void printPerson() = 0;
};



