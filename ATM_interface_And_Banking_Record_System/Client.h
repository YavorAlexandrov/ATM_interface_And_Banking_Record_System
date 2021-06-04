#pragma once
#include "Person.h"
#include "BankAccount.h"

class Client :
    public Person
{
    std::vector<BankAccount*> bankAccounts;
    
    void printPerson() override;

public:
    Client();
    Client(const std::string& EGN,
        const Name& fullName, const Date& date, const std::string& phoneNum,
        const std::string& address);

    Client(const Client& other) = delete;
    Client& operator = (const Client& other) = delete;
    ~Client();

    void deposit(int funds, int BAnum);
    void withdraw(int amount, int BAnum);
    void checkBalance(int BAnum);

    int getBAsize();

    std::vector<BankAccount*>& getBankAccs();



};

