#pragma once
class Date
{
	int day;
	int month;
	int year;

	bool validateDate(int day, int month, int year);
public:
	Date();
	Date(int day, int month, int year);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay();
	int getMonth();
	int getYear();
};

