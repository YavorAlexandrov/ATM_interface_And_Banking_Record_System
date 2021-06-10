#pragma warning (disable: 4996)
#include "Admin.h"
using namespace std;
Admin::Admin() : Person() {

}
Admin::Admin(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address): Person(EGN, fullName, date, phoneNum, address) {
	setUsername(username);
	setPassword(password);
}

void Admin::setUsername(const std::string& username)
{
	this->username = username;
}


void Admin::setPassword(const std::string password)
{
	this->password = password;
}

const std::string& Admin::getUsername()
{
	return this->username;
}


const std::string& Admin::getPassword()
{
	return this->password;
}

void Admin::createEmployeeAcc(std::string& username,  std::string& password,  std::string& EGN,
	 Name& fullName,  Date& date,  std::string& phoneNum, std::string& address, std::vector<Employee*> &employees, bool& isGood) {
	
	cout << "$ Input username:" << std::endl << "> ";
	cin >> username;
	
	
	cout << "$ Input password:" << endl << "> ";
	cin >> password;
	
	
	cout << "$ Input EGN:" << endl << "> ";
	cin >> EGN;
	for (int i = 0; i < employees.size(); i++) {
		if (EGN == employees[i]->getEGN()) {
			cout << "[Employee with this EGN exists!]";
			isGood = false;
			return;
		}
	}
	
	
	string firstName;
	cout << "$ Input first name:" << endl << "> ";
	cin >> firstName;
	
	string middleName;
	cout << "$ Input middle name:" << endl << "> ";
	cin >> middleName;
	
	string lastName;
	cout << "$ Input last name:" << endl << "> ";
	cin >> lastName;
	fullName = Name (firstName, middleName, lastName);
	
	string _date;
	cout << "$ Input date of birth (dd mm yyyy): " << endl << "> ";
	cin.ignore();
	getline(std::cin, _date);
	char source[11];
	int day, month, year;
	strcpy(source,_date.c_str());
	for (int i = 0; i < 3; i++) {
		char arr[5];
		copyNextWord(arr, source);
		switch (i) {
		case 0: day = atoi(arr); break;
		case 1: month = atoi(arr); break;
		case 2: year = atoi(arr); break;
		default: break;
		}
	}
	date = Date (day, month, year);
	
	
	
	cout << "$ Input phone number:" << endl << "> ";
	cin >> phoneNum;

	
	cout << "$ Input address:" << endl << "> ";
	cin.ignore();
	getline(std::cin, address);

	fstream outFile("Employees.txt", ios::app);
	outFile << username << "," << password << "," << EGN << "," << firstName << "," << middleName << "," << lastName << "," << date.getDay()<<" "<<date.getMonth()<<" "<< date.getYear() << "," << phoneNum << "," << address << endl;
	isGood = true;
}
void Admin::deleteEmployeeAcc(std::string& EGN, std::vector<Employee*>& employees, bool& isGood) {
	cout << "$ Input EGN:" << endl << "> ";
	cin >> EGN;
	for (int i = 0; i < employees.size(); i++) {
		if (EGN == employees[i]->getEGN()) {
			employees.erase(employees.begin()+i);
			isGood = true;
			return;
		}
	}
	isGood = false;
	cout << "[ Employee with this EGN does not exist! ]";
}
void Admin::printPerson() {
	std::cout << this->getUsername();
}



void Admin::copyNextWord(char* dest, char* source) {
	int i = 0;
	while (source[i] != ' ') {
		if (source[i] == '\0') {
			break;
		}
		dest[i] = source[i];
		i++;

	}

	dest[i] = '\0';
	int j = strlen(source);
	int k = 0;
	i++;
	while (i < j) {
		source[k] = source[i];
		i++;
		k++;
	}
	source[k] = '\0';

}