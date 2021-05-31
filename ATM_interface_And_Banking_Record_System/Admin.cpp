#pragma warning (disable: 4996)
#include "Admin.h"
using namespace std;
Admin::Admin() : Person() {

}
Admin::Admin(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address): Person(username, password, EGN, fullName, date, phoneNum, address) {

}

void Admin::createEmployeeAcc(std::string& username,  std::string& password,  std::string& EGN,
	 Name& fullName,  Date& date,  std::string& phoneNum, std::string& address) {
	
	cout << "$ Input username:" << std::endl << "> ";
	cin >> username;
	
	
	cout << "$ Input password:" << endl << "> ";
	cin >> password;
	
	
	cout << "$ Input EGN:" << endl << "> ";
	cin >> EGN;
	//validateEGN(EGN);
	
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
	cout << "$ Input date of birth:" << endl << "> ";
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
	
}
void Admin::deleteEmployeeAcc(const std::string EGN) {

}
void Admin::printPerson() {
	std::cout << this->getUsername();
}

void Admin::breakDownDate(int& _day, int& _month, int& _year, string date) {
	string day,month,year;
	if (date[1] == ' ') {
		day = date.substr(0, 1);
		if (date[3] == ' ') {
			month = date.substr(2, 1);
			year = date.substr(4, 4);
		}
		else {
			month = date.substr(2, 2);
			year = date.substr(5, 4);
		}
	}
	else {
		day = date.substr(0, 2);
		if (date[4] == ' ') {
			month = date.substr(3, 1);
			year = date.substr(5, 4);
		}
		else {
			month = date.substr(3, 2);
			year = date.substr(6, 4);
		}
	}
	char arr1[2], arr2[2], arr3[4];
	strcpy(arr1, day.c_str());
	strcpy(arr2, month.c_str());
	strcpy(arr3, year.c_str());

	_day = atoi(arr1);
	_month = atoi(arr2);
	_year = atoi(arr3);
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