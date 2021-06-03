#pragma once

#include"Client.h"
#include"Employee.h"
#include<vector>
#include"Admin.h"
class Database
{
	std::string convertToString(char* a, int size);
	void copyNextWord(char* dest, char* source);
	void load(const char* fileName, int sw);
	int countLines(const char* fileName);
	void writeAccsToFile(const char* fileName, int sw);
public:
	std::vector <Admin*> admins;
	std::vector<Employee*> employees;
	std::vector<Client*> clients;

	void addEmployee(int adminID);
	void deleteEmployee(int adminID);

	void addClient(int employeeID);
	void deleteClient(int employeeID);
	void loadClientBankAccs();
	void loadClientCards();

	void addAdmin(const Admin& a);

	void loadUsersFromFiles();
	void printEmployees();

	

	

	~Database();


};

