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
    Client(const std::string& username, const std::string& password, const std::string& EGN,
        const Name& fullName, const Date& date, const std::string& phoneNum,
        const std::string& address);

    Client(const Client& other);
    Client& operator = (const Client& other);
    ~Client();

    void deposit(int funds);
    void withdraw(int amount);
    void checkBalance();




};

