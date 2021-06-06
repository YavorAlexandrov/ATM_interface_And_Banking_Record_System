#include "Client.h"
void Client::printPerson() {
	
}

Client::Client():Person() {

}
Client::Client(const std::string& EGN, const Name& fullName, const Date& date, 
				const std::string& phoneNum, const std::string& address): Person(EGN, fullName, date, phoneNum, address) {

}

Client::~Client() {
	int size = bankAccounts.size();
	for (int i = 0; i < size; i++) {
		delete bankAccounts[i];
	}
}

int Client::getBAsize() {
	return bankAccounts.size();
}
std::vector<BankAccount*>& Client::getBankAccs() {
	return bankAccounts;
}

void Client::deposit(int funds, int BAnum) {
	if (funds < 0) {
		std::cout << "$ Invalid amount!\n";
		return;
	}
	bankAccounts[BAnum]->setAmount(bankAccounts[BAnum]->getAmount() + funds);

	std::cout << "$ Deposit successfull!\n";
}
void Client::withdraw(int amount, int BAnum) {
	if (amount < 0) {
		std::cout << "$ Invalid amount!\n";
		return;
	}
	if (bankAccounts[BAnum]->getAmount() - amount < 0) {
		std::cout << "Insufficient funds!\n";
		return;
	}
	bankAccounts[BAnum]->setAmount(bankAccounts[BAnum]->getAmount() - amount);
	std::cout << "$ Withdrawal successfull!\n";
}
void Client::checkBalance(int BAnum) {
	std::cout << "$ Current balance is: " << bankAccounts[BAnum]->getAmount() << '\n';
}