#pragma once
#include<vector>
#include<string>
#include"DebitCard.h"
class BankAccount
{
	std::string num;
	std::vector<DebitCard*> cards;
	double currentAmount;

public:
	BankAccount();
	BankAccount(const std::string& num, double amount);

	void setNum(const std::string& num);
	void setAmount(double amount);
	void addCard(std::string& cardNum);

	const std::string& getNum() const;
	double getAmount();
	std::vector<DebitCard*>& getCards();

	~BankAccount();
};

