#pragma once
#include "Person.h"
class Employee :
    public Person
{
    void printPerson() override;

public:
    Employee();
    Employee(const std::string& username, const std::string& password, const std::string& EGN,
        const Name& fullName, const Date& date, const std::string& phoneNum,
        const std::string& address);



};

