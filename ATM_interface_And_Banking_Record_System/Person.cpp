#include "Person.h"

Person::Person() {
	setUsername("unknown");
	setPassword("unknown");
	setEGN("unknown");
	Name n;
	setName(n);
	Date d;
	setDate(d);
	setPhone("unknown");
	setAddress("unknown");
}

Person::Person(const std::string& username, const std::string& password, const std::string& EGN, 
			   const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address) {
	
	setUsername(username);
	setPassword(password);
	setEGN(EGN);
	setName(fullName);
	setDate(date);
	setPhone(phoneNum);
	setAddress(address);
	
}

Person::~Person() {};


void Person::setUsername(const std::string& username)
{
	this->username = username;
}


void Person::setPassword(const std::string password)
{
	this->password = password;
}

void Person::setEGN(const std::string EGN) {
	this->EGN = EGN;
}

void Person::setName(const Name& name)
{
	this->fullName = name;
}


void Person::setDate(const Date& date)
{
	this->date = date;
}


void Person::setPhone(const std::string phone)
{
	this->phoneNum = phone;
}


void Person::setAddress(const std::string address)
{
	this->address = address;
}



const std::string& Person::getUsername()
{
	return this->username;
}


const std::string& Person::getPassword()
{
	return this->password;
}


const std::string& Person::getEGN()
{
	return this->EGN;
}


const Name& Person::getName() 
{
	return this->fullName;
}


const Date& Person::getDate()
{
	return this->date;
}


const std::string& Person::getPhone()
{
	return this->phoneNum;
}


const std::string& Person::getAddress()
{
	return this->address;
}
