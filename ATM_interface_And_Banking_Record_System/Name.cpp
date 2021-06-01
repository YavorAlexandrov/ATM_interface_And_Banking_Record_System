#include "Name.h"



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

const std::string& Name::getFirstName() const{
	return this->firstName;
}
const std::string& Name::getMiddleName() const{
	return this->middleName;
}
const std::string& Name::getLastName() const{
	return this->lastName;
}

void Name::printName() const{
	std::cout << firstName << " " << middleName << " " << lastName;
}