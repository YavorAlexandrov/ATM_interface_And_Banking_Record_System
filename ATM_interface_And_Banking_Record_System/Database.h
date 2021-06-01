#pragma once

//#include"Client.h"
#include"Employee.h"
#include<vector>
#include"Admin.h"
class Database
{
	std::vector <Admin*> admins;
	std::vector<Employee*> employees;
	//std::vector<Client*> clients;


	std::string convertToString(char* a, int size);
	void copyNextWord(char* dest, char* source);
	void load(const char* fileName, int sw);
	int countLines(const char* fileName);
	void writeAccsToFile(const char* fileName, int sw);
public:
	void addEmployee(int adminID);
	void deleteEmployee(int adminID);

	void addClient(const std::string& username, const std::string& password, const std::string& EGN,
				   const Name& fullName, const Date& date, const std::string& phoneNum,
				   const std::string& address);

	void addAdmin(const Admin& a);

	void loadUsersFromFiles();
	void printEmployees();

	~Database();


};

