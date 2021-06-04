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
			int cardsSize = BAsize = db.clients[i]->getBankAccs()[j]->getCards().size();
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
	cout << "To begin write 'help' to see all available commands.\n";
	string command;
	while (true) {
		cin >> command;
		//toLowerCase
		if (command == "help") {
			help(1);
		}
		else if (command == "loginasadmin") {
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
					string adminCommand;
					cin >> adminCommand;
					//toLowerCase
					if (adminCommand == "help") {
						help(2);
					}
					else if (adminCommand == "createemployeeaccount") {
						db.addEmployee(pos);
					}
					else if (adminCommand == "deleteemployeeaccount") {
						db.deleteEmployee(pos);
					}
					else if (adminCommand == "logout") {
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
			cout << "$ Please enter username: \n";
			string username;
			cin >> username;
			cout << "$ Please enter password: \n";
			string pass;
			cin >> pass;
			int pos;
			if (loginAsEmployee(username, pass, pos)) {
				cout << "Successfull login! Welcome " << db.employees[pos]->getName().getFirstName() << '\n'<<"> ";
				while (true) {
					string employeeCommand;
					cin >> employeeCommand;
					//toLowerCase
					if (employeeCommand == "help") {
						help(3);
					}
					else if (employeeCommand == "createclientaccount") {
						db.addClient(pos);
					}
					else if (employeeCommand == "deleteclientaccount") {
						db.deleteClient(pos);
					}
					else if (employeeCommand == "createbankaccount") {
						string EGN;
						cout << "Enter EGN to create new bank account: \n" << "> ";
						cin >> EGN;
						int amount;
						cout << "Enter starting amount for the account: \n> ";
						cin >> amount;
							db.employees[pos]->createBankAcc(EGN,  amount, db.clients);
					}
					else if (employeeCommand == "deletebankaccount") {
						db.employees[pos]->deleteBankAcc(db.clients);

					}
					else if (employeeCommand == "addnewcard") {
						string EGN;
						cout << "Enter EGN to create new bank account: \n" << "> ";
						cin >> EGN;
						string BAnum;
						cout << "Enter bank account number to add new card: \n" << "> ";
						cin >> BAnum;
						db.employees[pos]->addNewCard(EGN, BAnum, db.clients);
					}
					else if (employeeCommand == "deletecard") {
						db.employees[pos]->deleteCard(db.clients);
					}
					else if (employeeCommand == "clientsreport") {
						db.employees[pos]->printClients(db.clients);
					}
					else if (employeeCommand == "personalreport") {
						string EGN;
						cout << "Enter EGN to show report: \n" << "> ";
						cin >> EGN;
						db.employees[pos]->printClient(EGN, db.clients);
					}
					else if (employeeCommand == "logout") {
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
			cout << "$ Please enter card number: \n";
			string cardNum;
			cin >> cardNum;
			cout << "$ Please enter PIN: \n";
			int PIN;
			cin >> PIN;
			int clientPos;
			int BApos;
			//fix login for clients
			if (loginAsClient(cardNum, PIN, clientPos, BApos)) {
				cout << "Successfull login! Welcome " << db.clients[clientPos]->getName().getFirstName() << '\n' << "> ";
				while (true) {
					string clientCommand;
					cin >> clientCommand;
					//toLowerCase
					if (clientCommand == "help") {
						help(4);
					}
					else if (clientCommand == "deposit") {
						int funds;
						cout << "Please enter the amount to deposit: \n> ";
						cin >> funds;
						db.clients[clientPos]->deposit(funds, BApos);
					}
					else if (clientCommand == "withdraw") {
						int funds;
						cout << "Please enter the amount to withdraw: \n> ";
						cin >> funds;
						db.clients[clientPos]->withdraw(funds, BApos);
					}
					else if (clientCommand == "checkbalance") {
						db.clients[clientPos]->checkBalance(BApos);
					}
					else if (clientCommand == "logout") {
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
			cout << "Exitting...";
			break;
		}
		else {
			cout << "Invalid command!\n";
		}
	}
}