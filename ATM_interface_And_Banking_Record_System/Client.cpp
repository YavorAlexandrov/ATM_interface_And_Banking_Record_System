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