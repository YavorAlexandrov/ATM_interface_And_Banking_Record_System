#include "Employee.h"


Employee::Employee() : Person() {

}
Employee::Employee(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address) : Person(username, password, EGN, fullName, date, phoneNum, address) {

}

void Employee::printPerson() {
	
}