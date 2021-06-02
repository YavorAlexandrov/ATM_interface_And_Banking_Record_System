#pragma warning (disable: 4996)
#include "Employee.h"


Employee::Employee() : Person() {

}
Employee::Employee(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address) : Person(EGN, fullName, date, phoneNum, address) {
	setUsername(username);
	setPassword(password);
}

void Employee::setUsername(const std::string& username)
{
	this->username = username;
}


void Employee::setPassword(const std::string password)
{
	this->password = password;
}

const std::string& Employee::getUsername()
{
	return this->username;
}


const std::string& Employee::getPassword()
{
	return this->password;
}


void Employee::printPerson() {
	std::cout << this->getUsername() << " " << this->getPassword() << " " << this->getEGN() << " "; 
	getName().printName();
	std::cout << " ";
	std::cout << getDate().getDay() << "-" << getDate().getMonth() << "-" << getDate().getYear() << " ";
	std::cout<< this->getPhone() << " " << this->getAddress()<<"\n";
}

void Employee::createClientAcc(std::string& EGN, Name& fullName, Date& date, std::string& phoneNum, 
								std::string& address, std::vector<Client*>& clients, bool& isGood) {

	std::cout << "$ Input EGN:" << std::endl << "> ";
	std::cin >> EGN;
	for (int i = 0; i < clients.size(); i++) {
		if (EGN == clients[i]->getEGN()) {
			std::cout << "[Employee with this EGN exists!]";
			isGood = false;
			return;
		}
	}


	std::string firstName;
	std::cout << "$ Input first name:" << std::endl << "> ";
	std::cin >> firstName;

	std::string middleName;
	std::cout << "$ Input middle name:" << std::endl << "> ";
	std::cin >> middleName;

	std::string lastName;
	std::cout << "$ Input last name:" << std::endl << "> ";
	std::cin >> lastName;
	fullName = Name(firstName, middleName, lastName);

	std::string _date;
	std::cout << "$ Input date of birth:" << std::endl << "> ";
	std::cin.ignore();
	getline(std::cin, _date);
	char source[11];
	int day, month, year;
	strcpy(source, _date.c_str());
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
	date = Date(day, month, year);



	std::cout << "$ Input phone number:" << std::endl << "> ";
	std::cin >> phoneNum;


	std::cout << "$ Input address:" << std::endl << "> ";
	std::cin.ignore();
	getline(std::cin, address);

	std::ofstream outFile("Clients.txt", std::ios::app);
	outFile << EGN << "," << firstName << "," << middleName << "," << 
		lastName << "," << date.getDay() << " " << date.getMonth() << " " << date.getYear() 
		<< "," << phoneNum << "," << address << std::endl;
	isGood = true;
}

void Employee::copyNextWord(char* dest, char* source) {
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

void Employee::createBankAcc(const std::string& EGN, int amount, std::vector<Client*>& clients, bool& isGood) {// 00MYBANK<last 4 digits of EGN><bankAccsAmount>
	int size = clients.size();
	for (int i = 0; i < size; i++) {
		if (EGN == clients[i]->getEGN()) {
			int baSize = clients[i]->getBAsize() + 1;
			char buff[3];
			itoa(baSize, buff,10);
			std::string num = std::string(buff);

			std::string last4Digitis = EGN.substr(EGN.size() - 4, 4);
			std::string BAnum = "00MYBANK" + last4Digitis + num;
			clients[i]->getBankAccs().push_back(new BankAccount(BAnum, amount));
			std::string fileName = "BankAccounts/" + EGN + ".txt";
			std::ofstream f(fileName, std::ios::app);

			f << BAnum << ","<<amount<<'\n';

			return;
		}
	}
}