#include "BankAccount.h"

BankAccount::BankAccount() {
	setNum("");
	setAmount(0);
}
BankAccount::BankAccount(const std::string& num, int amount) {
	setNum(num);
	setAmount(amount);
}

void BankAccount::setNum(const std::string& num) {
	this->num = num;
}
void BankAccount::setAmount(int amount) {
	if (amount < 0)
		amount = 0;
	this->currentAmount = amount;
}
void BankAccount::addCard(std::string& cardNum) {
	cards.push_back(cardNum);
}

const std::string BankAccount::getNum() const{
	return this->num;
}