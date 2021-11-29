#include "date.h"
#include <string>
#include <assert.h>
#include <iostream>

namespace date {
	bool Date::checkDate(int year, int month, int day) {
		if (year < 0) {
			return false;
		}
		if ((month < 1) || (month > 12)) {
			return false;
		}
		if ((day < 1) || (day > 31)) {
			return false;
		}
		if ((month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12) && (day > 31)) {
			return false;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11)
			&& (day > 30)) {
			return false;
		}
		if ((month == 2) && (day > 29)) {
			return false;
		}
		if ((month == 2) && (day == 29)) {
			if ((year % 4) || ((year % 100 == 0) && (year % 400))) {
				return false;
			}
		}
		return true;
	}

	void Date::setdaywithoutassert(int day)
	{
		_day = day;
	}

	Date::Date(int year, int month, int day) {
		bool status = checkDate(year, month, day);
		assert(status == true && "Date is not valid");
		_year = year;
		_month = month;
		_day = day;
		//std::cout << "Constructor: " << _year << "/" << _month << "/" << _day << '\n';
	}

	Date::~Date() {
		//std::cout << "  Destructor: " << _year << "/" << _month << "/" << _day << '\n';
	}

	int Date::year() const {
		return _year;
	}
	int Date::month() const {
		return _month;
	}

	int Date::day() const {
		return _day;
	}

	bool Date::checkDate2()
	{
		if (_year < 0) {
			return false;
		}
		if ((_month < 1) || (_month > 12)) {
			return false;
		}
		if ((_day < 1) || (_day > 31)) {
			return false;
		}
		if ((_month == 1 || _month == 3 || _month == 5 || _month == 7
			|| _month == 8 || _month == 10 || _month == 12) && (_day > 31)) {
			return false;
		}
		if ((_month == 4 || _month == 6 || _month == 9 || _month == 11)
			&& (_day > 30)) {
			return false;
		}
		if ((_month == 2) && (_day > 29)) {
			return false;
		}
		if ((_month == 2) && (_day == 29)) {
			if ((_year % 4) || ((_year % 100 == 0) && (_year % 400))) {
				return false;
			}
		}
		return true;
	}

	std::string Date::toString() const {
		std::string month[12] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
		std::string to_display;
		to_display = std::to_string(_year) + "/" + month[_month - 1] + "/" + std::to_string(_day);
		return to_display;
	}

	void Date::setYear(int year) {
		assert(year >= 0 && "Year must be positive");
		_year = year;
	}

	void Date::setMonth(int month) {
		assert((month >= 1) && (month <= 12) && "Month must be between 1 and 121");
		_month = month;
	}

	void Date::setDay(int day) {
		bool status = checkDate(_year, _month, day);
		assert(status == true && "Day is not valid");
		_day = day;
	}

	void Date::nextDay() {
		bool status = checkDate(_year, _month, _day + 1);
		if (!status) {
			status = checkDate(_year, _month + 1, 1);
			if (!status) {
				_year++;
				_month = 1;
				_day = 1;
			}
			else {
				_month++;
				_day = 1;
			}
		}
		else {
			_day += 1;
		}
	}

	std::istream& operator>>(std::istream& input,Date& date)
	{
		int day, month, year;
		char ch1, ch2;
		input >> day >>ch1>> month>>ch2 >> year;
		//pour que la fonction checkDate2 dans system.cpp soit fausse et on redemande la saisie
		if (ch1 != '/' || ch2 != '/') {
			day += 32;
		}
		if (date.checkDate(year, month, day)) {
			date.setMonth(month);
			date.setYear(year);
			date.setDay(day);
			
		}
		else {//pour que la fonction checkDate2 dans system.cpp soit fausse et on redemande la saisie
			day += 32;
			date.setdaywithoutassert(day);
		}
		return input;
		
		
		// TODO: insérer une instruction return ici
	}

	bool operator == (const Date& d1, const Date& d2) { // check for equality
		if ((d1.day() == d2.day()) && (d1.month() == d2.month()) && (d1.year() == d2.year())) {
			return true;
		}
		return false;
	}

	bool operator !=(const Date& d1, const Date& d2) {
		return !(d1 == d2);
	}

	bool operator < (const Date& d1, const Date& d2) {
		if (d1.year() < d2.year()) {
			return true;
		}
		else if (d1.year() > d2.year()) {
			return false;
		}
		else { // same year
			if (d1.month() < d2.month()) {
				return true;
			}
			else if (d1.month() > d2.month()) {
				return false;
			}
			else { // same month
				if (d1.day() < d2.day()) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		return false;
	}


	bool operator > (const Date& d1, const Date& d2) {
		if (d1 == d2) {
			return false;
		}
		if (d1 < d2) {
			return false;
		}
		return true;
	}

	bool operator <=(const Date& d1, const Date& d2) {
		if (d1 == d2) {
			return true;
		}
		return (d1 < d2);
	}

	bool operator >=(const Date& d1, const Date& d2) {
		if (d1 == d2) {
			return true;
		}
		return (d1 > d2);
	}
	int operator-(const Date& d1, const Date& d2)
	{
		int days = (d1.day() - d2.day()) +(d1.month()-d2.month())*31 + (d1.year()-d2.year())*365;
		return days;
	}
	
}