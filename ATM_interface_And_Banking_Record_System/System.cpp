#include "System.h"
#include<iostream>
using namespace std;

System::System() {
	this->db = Database();
}

void System::loadData() {
	db.loadUsersFromFiles();
	db.loadClientBankAccs();
	db.loadClientCards();
}

bool System::loginAsAdmin(const std::string& username, const std::string& pass, int& pos) {
	int size = db.admins.size();
	for (int i = 0; i < size; i++) {
		if (username == db.admins[i]->getUsername() && pass == db.admins[i]->getPassword()) {
			pos = i;
			return true;
		}
	}
	return false;
}

bool System::loginAsEmployee(const std::string& username, const std::string& pass, int& pos) {
	int size = db.employees.size();
	for (int i = 0; i < size; i++) {
		if (username == db.employees[i]->getUsername() && pass == db.employees[i]->getPassword()) {
			pos = i;
			return true;
		}
	}
	return false;
}

bool System::loginAsClient(const std::string& cardNum, int PIN, int& clientPos, int& BApos) {
	int size = db.clients.size();
	for (int i = 0; i < size; i++) {
		int BAsize = db.clients[i]->getBankAccs().size();
		for (int j = 0; j < BAsize; j++) {
			int cardsSize = db.clients[i]->getBankAccs()[j]->getCards().size();
			for (int k = 0; k < cardsSize; k++) {
				if (cardNum == db.clients[i]->getBankAccs()[j]->getCards()[k]->getCardNum()
					&& PIN == db.clients[i]->getBankAccs()[j]->getCards()[k]->getPIN()) {
					clientPos = i;
					BApos = j;
					return true;
				}
			}
		}
	}
	return false;
}

void System::help(int sw) {
	if (sw == 1) {
		cout << "$ LoginAsAdmin - enter username and password to enter as admin.\n";
		cout << "$ LoginAsEmployee - enter username and password to enter as employee.\n";
		cout << "$ LoginAsClient - enter debit card number and PIN to enter as client.\n";
		cout << "$ help - see all possible commands.\n";
		cout << "$ exit - exit the app\n";
	}
	else if (sw == 2) {
		cout << "$ CreateEmployeeAccount - fill an form for a new employee.\n";
		cout << "$ DeleteEmployeeAccount - enter an EGN to delete employee.\n";
		cout << "$ help - see all possible commands.\n";
		cout << "$ logout - logout of the app.\n";
	}
	else if (sw == 3) {
		cout << "$ CreateClientAccount - fill a form for a new client.\n";
		cout << "$ DeleteClientAccount - enter an EGN to delete client.\n";
		cout << "$ CreateBankAccount - open a new bank account for a client.\n";
		cout << "$ DeleteBankAccount - close a bank account for a client.\n";
		cout << "$ AddNewCard - add to new card to an existing bank account for a client.\n";
		cout << "$ DeleteCard - delete an existing card for a client.\n";
		cout << "$ ClientsReport - show a report for all active clients of the bank.\n";
		cout << "$ PersonalReport - show a personal report to a client.\n";
		cout << "$ help - see all possible commands.\n";
		cout << "$ logout - logout of the app.\n";
	}
	else {
		cout << "$ Deposit - fund your account.\n";
		cout << "$ Withdraw - withdraw money from your account.\n";
		cout << "$ CheckBalance - check your current balance.\n";
		cout << "$ help - see all possible commands.\n";
		cout << "$ logout - logout of the app.\n";
	}
}

void System::start() {
	loadData();
	cout << "Welcome to the ATM interface and banking record system app!\n";
	cout << "To see all available commands at any time write 'help'.\n";
	string command;
	while (true) {
		cout << "> ";
		cin >> command;
		toLowerCase(command);
		if (command == "help") {
			system("cls");
			help(1);
		}
		else if (command == "loginasadmin") {
			system("cls");
			cout << "$ Please enter username: \n";
			string username;
			cin >> username;
			cout << "$ Please enter password: \n";
			string pass;
			cin >> pass;
			int pos;
			if (loginAsAdmin(username, pass, pos)) {
				cout << "Successfull login! Welcome " << db.admins[pos]->getName().getFirstName() << '\n';
				while (true) {
					cout << "> ";
					string adminCommand;
					cin >> adminCommand;
					toLowerCase(adminCommand);
					if (adminCommand == "help") {
						system("cls");
						help(2);
					}
					else if (adminCommand == "createemployeeaccount") {
						system("cls");
						db.addEmployee(pos);
					}
					else if (adminCommand == "deleteemployeeaccount") {
						system("cls");
						db.deleteEmployee(pos);
					}
					else if (adminCommand == "logout") {
						system("cls");
						cout << "Logging out...\n";
						break;
					}
					else {
						cout << "Invalid command!\n";
					}
				}
			}
			else {
				cout << "Login not successful!\n";
			}
		}
		else if (command == "loginasemployee") {
			system("cls");
			cout << "$ Please enter username: \n";
			string username;
			cin >> username;
			cout << "$ Please enter password: \n";
			string pass;
			cin >> pass;
			int pos;
			if (loginAsEmployee(username, pass, pos)) {
				cout << "Successfull login! Welcome " << db.employees[pos]->getName().getFirstName() << '\n';
				while (true) {
					cout << "> ";
					string employeeCommand;
					cin >> employeeCommand;
					toLowerCase(employeeCommand);
					if (employeeCommand == "help") {
						system("cls");
						help(3);
					}
					else if (employeeCommand == "createclientaccount") {
						system("cls");
						db.addClient(pos);
					}
					else if (employeeCommand == "deleteclientaccount") {
						system("cls");
						db.deleteClient(pos);
					}
					else if (employeeCommand == "createbankaccount") {
						system("cls");
						string EGN;
						cout << "Enter EGN to create new bank account: \n" << "> ";
						cin >> EGN;
						int amount;
						cout << "Enter starting amount for the account: \n> ";
						cin >> amount;
							db.employees[pos]->createBankAcc(EGN,  amount, db.clients);
					}
					else if (employeeCommand == "deletebankaccount") {
						system("cls");
						db.employees[pos]->deleteBankAcc(db.clients);

					}
					else if (employeeCommand == "addnewcard") {
						system("cls");
						string EGN;
						cout << "Enter EGN to create new bank account: \n" << "> ";
						cin >> EGN;
						string BAnum;
						cout << "Enter bank account number to add new card: \n" << "> ";
						cin >> BAnum;
						db.employees[pos]->addNewCard(EGN, BAnum, db.clients);
					}
					else if (employeeCommand == "deletecard") {
						system("cls");
						db.employees[pos]->deleteCard(db.clients);
					}
					else if (employeeCommand == "clientsreport") {
						system("cls");
						db.employees[pos]->printClients(db.clients);
					}
					else if (employeeCommand == "personalreport") {
						system("cls");
						string EGN;
						cout << "Enter EGN to show report: \n" << "> ";
						cin >> EGN;
						db.employees[pos]->printClient(EGN, db.clients);
					}
					else if (employeeCommand == "logout") {
						system("cls");
						cout << "Logging out...\n";
						break;
					}
					else {
						cout << "Invalid command!\n";
					}
				}
			}
			else {
				cout << "Login not successful!\n";
			}
		}
		else if (command == "loginasclient") {
			system("cls");
			cout << "$ Please enter card number: \n";
			string cardNum;
			cin >> cardNum;
			cout << "$ Please enter PIN: \n";
			int PIN;
			cin >> PIN;
			int clientPos;
			int BApos;
			
			if (loginAsClient(cardNum, PIN, clientPos, BApos)) {
				cout << "Successfull login! Welcome " << db.clients[clientPos]->getName().getFirstName() << '\n' << "> ";
				while (true) {
					cout << "> ";
					string clientCommand;
					cin >> clientCommand;
					toLowerCase(clientCommand);
					if (clientCommand == "help") {
						system("cls");
						help(4);
					}
					else if (clientCommand == "deposit") {
						system("cls");
						int funds;
						cout << "Please enter the amount to deposit: \n> ";
						cin >> funds;
						db.clients[clientPos]->deposit(funds, BApos);
						int size = db.clients[clientPos]->getBankAccs().size();
						std::string fileName = "BankAccounts/" + db.clients[clientPos]->getEGN() + ".txt";
						std::ofstream f(fileName, std::ios::trunc);
						for (int i = 0; i < size; i++) {
							f << db.clients[clientPos]->getBankAccs()[i]->getNum() << "," << db.clients[clientPos]->getBankAccs()[i]->getAmount() << "\n";
						}
						f.close();
					}
					else if (clientCommand == "withdraw") {
						system("cls");
						int funds;
						cout << "Please enter the amount to withdraw: \n> ";
						cin >> funds;
						db.clients[clientPos]->withdraw(funds, BApos);
						int size = db.clients[clientPos]->getBankAccs().size();
						std::string fileName = "BankAccounts/" + db.clients[clientPos]->getEGN() + ".txt";
						std::ofstream f(fileName, std::ios::trunc);
						for (int i = 0; i < size; i++) {
							f << db.clients[clientPos]->getBankAccs()[i]->getNum() << "," << db.clients[clientPos]->getBankAccs()[i]->getAmount() << "\n";
						}
						f.close();
					}
					else if (clientCommand == "checkbalance") {
						system("cls");
						db.clients[clientPos]->checkBalance(BApos);
					}
					else if (clientCommand == "logout") {
						system("cls");
						cout << "Logging out...\n";
						break;
					}
					else {
						cout << "Invalid command!\n";
					}
				}
			}
			else {
				cout << "Login not successful!\n";
			}
		}
		else if (command == "exit") {
			system("cls");
			cout << "Exitting...\n";
			break;
		}
		else {
			cout << "Invalid command!\n";
		}
	}
}

void System::toLowerCase(std::string& str) {
	int size = str.length();
	for (int i = 0; i < size; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + ('a' - 'A');
		}
	}
}