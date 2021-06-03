#pragma once
#include<string>
#include <stdlib.h>    
#include <time.h> 

class DebitCard
{
	std::string cardNum;
	int PIN;

public:
	DebitCard();
	DebitCard(const std::string& cardNum);
	DebitCard(const std::string& cardNum, int PIN);

	void setCardNum(const std::string& cardNum);
	void setPIN();

	const std::string& getCardNum();
	const int getPIN();


};

