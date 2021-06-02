#include "Person.h"

Person::Person() {
	
	setEGN("unknown");
	Name n;
	setName(n);
	Date d;
	setDate(d);
	setPhone("unknown");
	setAddress("unknown");
}

Person::Person(const std::string& EGN, 
			   const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address) {
	
	
	setEGN(EGN);
	setName(fullName);
	setDate(date);
	setPhone(phoneNum);
	setAddress(address);
	
}

Person::~Person() {};




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
