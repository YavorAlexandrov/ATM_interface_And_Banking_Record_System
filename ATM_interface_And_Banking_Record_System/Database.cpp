#include "Database.h"

void Database::addEmployee(int adminID) {
	std::string username, password, EGN, phoneNum, address;
	Name fullName;
	Date date;
	admins[adminID]->createEmployeeAcc(username, password, EGN, fullName, date, phoneNum, address);
	employees.push_back(new Employee(username, password, EGN, fullName, date, phoneNum, address));

}

void Database::addClient(const std::string& username, const std::string& password, const std::string& EGN,
	const Name& fullName, const Date& date, const std::string& phoneNum,
	const std::string& address) {


}

void Database::addAdmin(const Admin& a) {
	admins.push_back(new Admin(a));

}
