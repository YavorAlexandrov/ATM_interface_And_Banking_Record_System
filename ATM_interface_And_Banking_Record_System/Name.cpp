#include "Name.h"
#include<iostream>


Name::Name() {
	Name("unknown", "unknown", "unknown");
}
Name::Name(const std::string& fName, const std::string& mName, const std::string& lName) {
	setFirstName(fName);
	setMiddleName(mName);
	setLastName(lName);
}

void Name::setFirstName(const std::string& fName) {
	this->firstName = fName;
}
void Name::setMiddleName(const std::string& mName) {
	this->middleName = mName;
}
void Name::setLastName(const std::string& lName) {
	this->lastName = lName;
}

const std::string& Name::getFirstName() {
	return this->firstName;
}
const std::string& Name::getMiddleName() {
	return this->middleName;
}
const std::string& Name::getLastName() {
	return this->lastName;
}

void Name::printName() {
	std::cout << firstName << " " << middleName << " " << lastName;
}