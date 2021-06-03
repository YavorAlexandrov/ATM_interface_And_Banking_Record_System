#include "DebitCard.h"
DebitCard::DebitCard() {
	setCardNum("");
}
DebitCard::DebitCard(const std::string& cardNum) {
	setCardNum(cardNum);
	setPIN();
}
DebitCard::DebitCard(const std::string& cardNum, int PIN) {
	setCardNum(cardNum);
	this->PIN = PIN;
}

void DebitCard::setCardNum(const std::string& cardNum) {
	this->cardNum = cardNum;
}
void DebitCard::setPIN() {
	srand(time(NULL));
	this->PIN = rand() % 9000 + 1000;
}

const std::string& DebitCard::getCardNum() {
	return cardNum;
}
const int DebitCard::getPIN() {
	return PIN;
}