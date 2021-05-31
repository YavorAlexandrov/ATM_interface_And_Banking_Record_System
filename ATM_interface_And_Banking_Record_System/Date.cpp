#include "Date.h"

Date::Date() {
	Date(1, 1, 1900);
}
Date::Date(int day, int month, int year) {
	if (!validateDate(day, month, year)) {
		setDay(1);
		setMonth(1);
		setYear(1900);
	}
	else {
		setDay(day);
		setMonth(month);
		setYear(year);
	}
}

void Date::setDay(int day) {
	this->day = day;
}
void Date::setMonth(int month) {
	this->month = month;
}
void Date::setYear(int year) {
	this->year = year;
}

int Date::getDay() const {
	return day;
}
int Date::getMonth() const {
	return month;
}
int Date::getYear() const {
	return year;
}


bool Date::validateDate(int day, int month, int year) {
	if (month < 1 || month>12) {
		return false;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 1 || day>31) {
			return false;
		}
	}
	else if (month == 2) {
		if (year % 4 == 0) {
			if (day < 1 || day>29) {
				return false;
			}
			else if (day < 1 || day>28) {
				return false;
			}
		}
	}
	else if (day < 1 || day>30) {
		return false;
	}
	return true;
}