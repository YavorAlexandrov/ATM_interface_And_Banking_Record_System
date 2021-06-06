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

void Employee::createBankAcc(const std::string& EGN, double amount, std::vector<Client*>& clients) {// 00MYBANK<last 4 digits of EGN><bankAccsAmount>
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
			f.close();
			std::cout << "[ Bank account added succsessfully! ]\n";
			return;
		}
	}
	system("cls");
	std::cout << "[ Client with this EGN does not exist! ]\n";
}

void Employee::deleteClientAcc(std::string& EGN, std::vector<Client*>& clients, bool& isGood) {
	std::cout << "$ Input EGN:" << std::endl << "> ";
	std::cin >> EGN;
	int size = clients.size();
	for (int i = 0; i < size; i++) {
		if (EGN == clients[i]->getEGN()) {
			int BAsize = clients[i]->getBankAccs().size();
			for (int j = 0; j < BAsize; j++) {
				//remove files with cards and bankAccs
				std::string fileName = "BankAccounts/Cards/" + clients[i]->getBankAccs()[j]->getNum() + ".txt";
				remove(fileName.c_str());
			}
			std::string fileName = "BankAccounts/" + clients[i]->getEGN() + ".txt";
			remove(fileName.c_str());
			clients.erase(clients.begin() + i);
			isGood = true;
			return;
		}
	}
	isGood = false;
	std::cout << "[ Client with this EGN does not exist! ]";
}

void Employee::addNewCard(const std::string& EGN,const std::string& BAnum, std::vector<Client*>& clients) {
	int size = clients.size();
	for (int i = 0; i < size; i++) {
		if (EGN == clients[i]->getEGN()) {
			int BAsize = clients[i]->getBankAccs().size();
			for (int j = 0; j < BAsize; j++) {
				if (BAnum == clients[i]->getBankAccs()[j]->getNum()) {
					int cardsSize = clients[i]->getBankAccs()[j]->getCards().size() + 1;
					char buff[3];
					itoa(cardsSize, buff, 10);
					std::string num = std::string(buff);
					std::string last4Digitis = EGN.substr(EGN.size() - 4, 4);
					std::string CardNum = "00" + last4Digitis + num;

					clients[i]->getBankAccs()[j]->addCard(CardNum);
					std::string fileName = "BankAccounts/Cards/"+ clients[i]->getEGN() + clients[i]->getBankAccs()[j]->getNum() + ".txt";
					std::ofstream f(fileName, std::ios::app);
					int pos = clients[i]->getBankAccs()[j]->getCards().size() - 1;
					f << CardNum << "," << clients[i]->getBankAccs()[j]->getCards()[pos]->getPIN() << '\n';
					f.close();
					std::cout << "[ Debit card added succsessfully! ]\n";
					return;


				}
			}
			system("cls");
			std::cout << "[ Client with this Bank account does not exist! ]\n";
		}
	}
	system("cls");
	std::cout << "[ Client with this EGN does not exist! ]\n";
}

void Employee::deleteBankAcc(std::vector<Client*>& clients) {
	std::string EGN, BAnum;
	
	std::cout << "$ Input EGN:" << std::endl << "> ";
	std::cin >> EGN;
	std::cout << "$ Input Bank account number:" << std::endl << "> ";
	std::cin >> BAnum;

	int size = clients.size();
	for (int i = 0; i < size; i++) {
		if (EGN == clients[i]->getEGN()) {
			int BAsize = clients[i]->getBankAccs().size();
			for (int j = 0; j < BAsize; j++) {
				if (BAnum == clients[i]->getBankAccs()[j]->getNum()) {
					std::string fileName = "BankAccounts/Cards/" + clients[i]->getBankAccs()[j]->getNum() + ".txt";
					remove(fileName.c_str());
					clients[i]->getBankAccs().erase(clients[i]->getBankAccs().begin() + j);

					std::string fileName2 = "BankAccounts/" + clients[i]->getEGN() + ".txt";
					std::ofstream f(fileName2, std::ios::trunc);
					for (int k = 0; k < BAsize - 1; k++) {
						f << clients[i]->getBankAccs()[k]->getNum() << "," << clients[i]->getBankAccs()[k]->getAmount() << '\n';
					}
					f.close();
					system("cls");
					std::cout<< "[ Bank account deleted succsessfully! ]\n";
					return;
				}
			}
			system("cls");
			std::cout << "[ Client with this Bank account does not exist! ]\n";
		}
		system("cls");
		std::cout << "[ Client with this EGN does not exist! ]\n";
	}

}

void Employee::deleteCard(std::vector<Client*>& clients) {
	std::string EGN, BAnum, cardNum;
	std::cout << "$ Input EGN:" << std::endl << "> ";
	std::cin >> EGN;
	std::cout << "$ Input Bank account number:" << std::endl << "> ";
	std::cin >> BAnum;
	std::cout << "$ Input Card number:" << std::endl << "> ";
	std::cin >> cardNum;

	int size = clients.size();
	for (int i = 0; i < size; i++) {
		if (EGN == clients[i]->getEGN()) {
			int BAsize = clients[i]->getBankAccs().size();
			for (int j = 0; j < BAsize; j++) {
				if (BAnum == clients[i]->getBankAccs()[j]->getNum()) {
					int cardsSize = clients[i]->getBankAccs()[j]->getCards().size();
					for (int k = 0; k < cardsSize; k++) {
						if (cardNum == clients[i]->getBankAccs()[j]->getCards()[k]->getCardNum()) {
							clients[i]->getBankAccs()[j]->getCards().erase(clients[i]->getBankAccs()[j]->getCards().begin() + k);

							std::string fileName = "BankAccounts/Cards/" + clients[i]->getBankAccs()[j]->getNum() + ".txt";
							std::ofstream f(fileName, std::ios::trunc);
							for (int l = 0; l < cardsSize - 1; l++) {
								f << clients[i]->getBankAccs()[j]->getCards()[l]->getCardNum() << "," << clients[i]->getBankAccs()[j]->getCards()[l]->getPIN()<<'\n';
							}
							f.close();
							system("cls");
							std::cout << "[ Debit card deleted succsessfully! ]";
							return;
						}
					}
					system("cls");
					std::cout << "[ Client with this Card number does not exist! ]";
				}
			}
			system("cls");
			std::cout << "[ Client with this Bank account does not exist! ]";
		}
		system("cls");
		std::cout << "[ Client with this EGN does not exist! ]";
	}
}

void Employee::printClients(std::vector<Client*>& clients) {
	std::cout << "Clients list:\n";
	int size = clients.size();
	for (int i = 0; i < size; i++) {
		int cardsAmount = 0;
		int BAsize = clients[i]->getBankAccs().size();
		for (int j = 0; j < BAsize; j++) {
			cardsAmount += clients[i]->getBankAccs()[j]->getCards().size();
		}
		std::cout << i+1 << ") " << "EGN: " << clients[i]->getEGN() << " | Number of bank accounts: "
			<< clients[i]->getBankAccs().size() << " | Number of cards:" << cardsAmount<<'\n';
	}
}

void Employee::printClient(const std::string& EGN, std::vector<Client*>& clients) {
	int size = clients.size();
	for (int i = 0; i < size; i++) {
		if (EGN == clients[i]->getEGN()) {
			std::cout << "-------Client Report-------\n";
			std::cout << "EGN: " << EGN << '\n';
			std::cout << "Name: "; clients[i]->getName().printName(); std::cout << '\n';
			std::cout << "BirthDate: "; clients[i]->getDate().printDate();
			std::cout << "Phone number: " << clients[i]->getPhone() << '\n';
			std::cout << "Address: " << clients[i]->getAddress() << '\n';

			int BAsize = clients[i]->getBankAccs().size();
			for (int j = 0; j < BAsize; j++) {
				std::cout << "\n****Account" << j + 1 << "****\n";
				std::cout << "Acc number: " << clients[i]->getBankAccs()[j]->getNum() << '\n';
				std::cout << "Balance: " << clients[i]->getBankAccs()[j]->getAmount() << '\n';
				std::cout << "Number of cards: " << clients[i]->getBankAccs()[j]->getCards().size() << '\n';
				int cardsSize = clients[i]->getBankAccs()[j]->getCards().size();
				for (int k = 0; k < cardsSize; k++) {
					std::cout << "   $Card" << k + 1 << "$   \n";
					std::cout << "Card number: " << clients[i]->getBankAccs()[j]->getCards()[k]->getCardNum() << '\n';
					std::cout << "PIN: " << clients[i]->getBankAccs()[j]->getCards()[k]->getPIN() << '\n';
				}
			}

			return;

		}
	}
	system("cls");
	std::cout << "[ Client with this EGN does not exist! ]\n";
}
