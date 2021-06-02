#pragma once
#include<vector>
#include<string>
class BankAccount
{
	std::string num;
	std::vector<std::string> cards;
	int currentAmount;

public:
	BankAccount();
	BankAccount(const std::string& num, int amount);

	void setNum(const std::string& num);
	void setAmount(int amount);
	void addCard(std::string& cardNum);

	const std::string getNum() const;

};

