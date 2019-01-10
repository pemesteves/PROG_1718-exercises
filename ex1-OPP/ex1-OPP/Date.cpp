#pragma once

#include "Date.h"

#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

Date::Date()
{
	istringstream iss(__DATE__);
	string m;
	char space;

	iss >> m >> space >> this->day >> space >> this->year;

	if (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n')
		this->month = 1;
	else if (__DATE__[0] == 'F')
		this->month = 2;
	else if (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
		this->month = 3;
	else if (__DATE__[0] == 'A' && __DATE__[1] == 'p')
		this->month = 4;
	else if (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
		this->month = 5;
	else if (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
		this->month = 6;
	else if (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
		this->month = 7;
	else if (__DATE__[0] == 'A' && __DATE__[1] == 'u')
		this->month = 8;
	else if (__DATE__[0] == 'S')
		this->month = 9;
	else if (__DATE__[0] == 'O')
		this->month = 10;
	else if (__DATE__[0] == 'N')
		this->month = 11;
	else
		this->month = 12;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}


Date::Date(string yearMonthDay)
{
	istringstream iss(yearMonthDay);
	char barra;
	unsigned int year, month, day;

	iss >> year >> barra >> month >> barra >> day;

	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

 const unsigned int Date::getYear()
{
	return this->year;
}

 unsigned int Date::getMonth()
{
	return this->month;
}

 unsigned int Date::getDay()
{
	return this->day;
}

string Date::getDate()
{
	ostringstream oss;

	oss << this->year << "/" << this->month << "/" << this->day;

	return oss.str();
}

void Date::show()
{
	cout << this->year << "/" << this->month << "/" << this->day;
}

bool Date::isValid()
{
	bool valid = true;

	if (this->month > 12 || this->month < 1)
		valid = false;
	else if (this->day > 31 || this->day < 1)
		valid = false;
	else
	{
		unsigned int nDays;
		nDays = numberOfDays(this->year, this->month);
		if (this->day != nDays)
			valid = false;
	}

	return valid;
}

unsigned int Date::numberOfDays(unsigned int year, unsigned int month)
{
	bool bis = false;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		bis = true;
	
	unsigned int nDays;

	switch (month)
	{
	case 2:
		if (bis)
			nDays = 29;
		else
			nDays = 28;
		break;
	case 4: case 6: case 9: case 11:
		nDays = 30;
		break;
	default:
		nDays = 31;
	}

	return nDays;
}

bool Date::isEqualTo(const Date &date)
{
	bool equal = true;
	Date d = date; //Nova data para habilitar o uso dos métodos getYear, getMonth e getDay
	if (this->year != d.getYear())
		equal = false;
	else if (this->month != d.getMonth())
		equal = false;
	else if (this->day != d.getDay())
		equal = false;

	return equal;
}

bool Date::isNotEqualTo(const Date &date)
{
	bool notEqual = false;
	Date d = date; //Nova data para habilitar o uso dos métodos getYear, getMonth e getDay
	if (this->year != d.getYear())
		notEqual = true;
	else if (this->month != d.getMonth())
		notEqual = true;
	else if (this->day != d.getDay())
		notEqual = true;
	
	return notEqual;
}

bool Date::isAfter(const Date &date)
{
	Date d = date; //Nova data para habilitar o uso dos métodos getYear, getMonth e getDay
	bool after;

	if (this->year < d.getYear())
		after = false;
	else if (this->year > d.getYear())
		after = true;
	else
	{
		if (this->month < d.getMonth())
			after = false;
		else if (this->month > d.getMonth())
			after = true;
		else
		{
			if (this->day > d.getDay())
				after = true;
			else
				after = false;
		}
	}

	return after;
}

bool Date::isBefore(const Date &date)
{
	Date d = date; //Nova data para habilitar o uso dos métodos getYear, getMonth e getDay
	bool before;

	if (this->year > d.getYear())
		before = false;
	else if (this->year < d.getYear())
		before = true;
	else
	{
		if (this->month > d.getMonth())
			before = false;
		else if (this->month < d.getMonth())
			before = true;
		else
		{
			if (this->day < d.getDay())
				before = true;
			else
				before = false;
		}
	}

	return before;
}