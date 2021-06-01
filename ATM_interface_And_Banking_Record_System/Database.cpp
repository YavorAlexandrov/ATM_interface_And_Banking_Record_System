#include "Database.h"
#include<fstream>

void Database::addEmployee(int adminID) {
	std::string username, password, EGN, phoneNum, address;
	Name fullName;
	Date date;
	bool isGood;
	admins[adminID]->createEmployeeAcc(username, password, EGN, fullName, date, phoneNum, address, employees, isGood);
	if (isGood) {
		employees.push_back(new Employee(username, password, EGN, fullName, date, phoneNum, address));
		system("cls");
		std::cout << "[ Employee account successfully created! ]"<<'\n';
	}

}

void Database::deleteEmployee(int adminID) {
	std::string EGN;
	bool isGood;
	admins[adminID]->deleteEmployeeAcc(EGN, employees, isGood);
	if (isGood) {
		writeAccsToFile("Employees.txt", 2);
		system("cls");
		std::cout << "[ Employee account successfully deleted! ]"<<'\n';
	}


}

void Database::addClient(const std::string& username, const std::string& password, const std::string& EGN,
	const Name& fullName, const Date& date, const std::string& phoneNum,
	const std::string& address) {


}

void Database::addAdmin(const Admin& a) {
	admins.push_back(new Admin(a));

}

void Database::loadUsersFromFiles() {
	load("Employees.txt", 2);
	load("Admins.txt", 1);
	//load("Clients.txt",3);
}

std::string Database::convertToString(char* a, int size)
{
	int i;
	std::string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

void Database::copyNextWord(char* dest, char* source) {
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

void Database::printEmployees() {
	for (int i = 0; i < employees.size(); i++) {
		employees[i]->printPerson();
	}
}

void Database::load(const char* fileName, int sw) {
	std::ifstream in(fileName);
	int count = countLines(fileName);
	for(int i=0;i<count-1;i++) {
		char usernameBuff[64];
		in.get(usernameBuff, 64, ',');
		in.seekg(1, 1);
		std::string username;
		username = convertToString(usernameBuff, strlen(usernameBuff));

		char passwordBuff[64];
		in.get(passwordBuff, 64, ',');
		in.seekg(1, 1);
		std::string password;
		password = convertToString(passwordBuff, strlen(passwordBuff));

		char EGNbuff[16];
		in.get(EGNbuff, 16, ',');
		in.seekg(1, 1);
		std::string EGN;
		EGN = convertToString(EGNbuff, strlen(EGNbuff));

		char firstNameBuff[64];
		in.get(firstNameBuff, 64, ',');
		in.seekg(1, 1);
		std::string firstName;
		firstName = convertToString(firstNameBuff, strlen(firstNameBuff));

		char middleNameBuff[64];
		in.get(middleNameBuff, 64, ',');
		in.seekg(1, 1);
		std::string middleName;
		middleName = convertToString(middleNameBuff, strlen(middleNameBuff));

		char lastNameBuff[64];
		in.get(lastNameBuff, 64, ',');
		in.seekg(1, 1);
		std::string lastName;
		lastName = convertToString(lastNameBuff, strlen(lastNameBuff));

		Name name(firstName, middleName, lastName);

		char dateBuff[16];
		in.get(dateBuff, 16, ',');
		in.seekg(1, 1);

		int day, month, year;

		for (int i = 0; i < 3; i++) {
			char arr[10000];
			copyNextWord(arr, dateBuff);
			switch (i) {
			case 0: day = atoi(arr); break;
			case 1: month = atoi(arr); break;
			case 2: year = atoi(arr); break;
			default: break;
			}
		}
		Date date(day, month, year);

		char phoneBuff[64];
		in.get(phoneBuff, 64, ',');
		in.seekg(1, 1);
		std::string phone;
		phone = convertToString(phoneBuff, strlen(phoneBuff));

		char addressBuff[64];
		in.get(addressBuff, 64, '\n');
		in.seekg(2, 1);
		std::string address;
		address = convertToString(addressBuff, strlen(addressBuff));


		switch (sw)
		{
		case 1: admins.push_back(new Admin(username, password, EGN, name, date, phone, address)); break;
		case 2: employees.push_back(new Employee(username, password, EGN, name, date, phone, address)); break;
		case 3: //clients.push_back(new Cient(username, password, EGN, name, date, phone, address)); break;
		default:
			break;
		}
		

	}
	in.close();
}

int Database::countLines(const char* fileName)
{
	std::ifstream f(fileName);
	if (!f.is_open())
		return -1;
	int linesCount = 0;

	while (!f.eof())
	{
		char buff[1024];
		f.getline(buff, 1024);
		linesCount++;
	}
	f.close();

	return linesCount;

}

Database::~Database() {
	for (int i = 0; i < admins.size(); i++) {
		delete admins[i];
	}
	for (int i = 0; i < employees.size(); i++) {
		delete employees[i];
	}
	/*for (int i = 0; i < clients.size(); i++) {
		delete clients[i];
	}*/
}

void Database::writeAccsToFile(const char* fileName, int sw) {
	if (sw == 1) {
		
		std::ofstream f(fileName, std::ios::trunc);
		int size = admins.size();
		for (int i = 0; i < size; i++) {
			f << admins[i]->getUsername() << "," << admins[i]->getPassword() << "," 
				<< admins[i]->getEGN() << "," << admins[i]->getName().getFirstName() << "," << admins[i]->getName().getMiddleName() 
				<< "," << admins[i]->getName().getLastName() << "," << admins[i]->getDate().getDay() << " " << admins[i]->getDate().getMonth() << " " << admins[i]->getDate().getYear()  << "," << admins[i]->getPhone() 
				<< "," << admins[i]->getAddress() << '\n';

		}
		f.close();
	}
	else if (sw == 2) {
		
		std::ofstream f(fileName, std::ios::trunc);
		int size = employees.size();
		for (int i = 0; i < size; i++) {
			f << employees[i]->getUsername() << "," << employees[i]->getPassword() << ","
				<< employees[i]->getEGN() << "," << employees[i]->getName().getFirstName() << "," << employees[i]->getName().getMiddleName()
				<< "," << employees[i]->getName().getLastName() << "," << employees[i]->getDate().getDay() << " " << employees[i]->getDate().getMonth() << " " 
				<< employees[i]->getDate().getYear() << "," << employees[i]->getPhone() << "," << employees[i]->getAddress() << '\n';

		}
		f.close();
	}
	else {
		/*
		
		std::ofstream f(fileName, std::ios::trunc);
		int size = clients.size();
		for (int i = 0; i < size; i++) {
			f << clients[i]->getUsername() << "," << clients[i]->getPassword() << ","
				<< clients[i]->getEGN() << "," << clients[i]->getName().getFirstName() << "," << clients[i]->getName().getMiddleName()
				<< "," << clients[i]->getName().getLastName() << "," << clients[i]->getDate().getDay() << " " << clients[i]->getDate().getMonth() << " "
				<< clients[i]->getDate().getYear() << "," << clients[i]->getPhone() << "," << clients[i]->getAddress() << '\n';

		}
		f.close();*/
	}

}