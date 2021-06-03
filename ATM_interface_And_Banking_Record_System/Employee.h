#pragma once
#include"Client.h"
#include<fstream>
#include<vector>
#include<fstream>
class Employee :
    public Person
{
    std::string username;
    std::string password;

    void copyNextWord(char* dest, char* source);
public:
    Employee();
    Employee(const std::string& username, const std::string& password, const std::string& EGN,
        const Name& fullName, const Date& date, const std::string& phoneNum,
        const std::string& address);

    void setUsername(const std::string& username);
    void setPassword(const std::string password);

    const std::string& getUsername();
    const std::string& getPassword();

    void printPerson() override;

    void createClientAcc(std::string& EGN, Name& fullName, Date& date, std::string& phoneNum, 
                        std::string& address, std::vector<Client*>& clients, bool& isGood);

    void deleteClientAcc(std::string& EGN, std::vector<Client*>& client, bool& isGood);

    void createBankAcc(const std::string& EGN, double amount, std::vector<Client*>& clients, bool& isGood);// 00MYBANK<last 4 digits of EGN><bankAccsAmount>

    void addNewCard(const std::string& EGN, const std::string& BAnum, std::vector<Client*>& clients, bool& isGood);//00<last 4 digits of EGN><cardsAmount>

    void deleteBankAcc(std::vector<Client*>& clients); //check EGN, check BAnum

    void deleteCard(std::vector<Client*>& clients); //check EGN, check BAnum, check cardNum

    void printClients(std::vector<Client*>& clients);

    void printClient(const std::string& EGN, std::vector<Client*>& clients);

};

