#include "BankAccount.h"

BankAccount::BankAccount() {
	setNum("");
	setAmount(0);
}
BankAccount::BankAccount(const std::string& num, double amount) {
	setNum(num);
	setAmount(amount);
}

void BankAccount::setNum(const std::string& num) {
	this->num = num;
}
void BankAccount::setAmount(double amount) {
	if (amount < 0) {
		
		amount = 0;
	}
	this->currentAmount = amount;
}
void BankAccount::addCard(std::string& cardNum) {
	
	cards.push_back(new DebitCard(cardNum));
}

const std::string& BankAccount::getNum() const{
	return this->num;
}
double BankAccount::getAmount() {
	return this->currentAmount;
}

std::vector<DebitCard*>& BankAccount::getCards() {
	return cards;
}

BankAccount::~BankAccount() {
	int size = cards.size();
	for (int i = 0; i < size; i++)
		delete cards[i];
}