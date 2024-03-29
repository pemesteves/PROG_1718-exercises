// ex1-OPP.cpp : define o ponto de entrada para o aplicativo do console.
//
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	typedef unsigned int ui;

	Date d1(1, 1, 1);
	Date d2("0001/01/01");

	d1.setYear(1999);
	d2.setYear(2001);

	d1.setMonth(10);
	d2.setMonth(4);
	 
	d1.setDay(10);
	d2.setDay(4);
	d1.show();
	d2.show();

	d1.setDate(2000, 11, 11);
	d2.setDate(2002, 5, 5);

	ui y1, y2, m1, m2, di1, di2;

	y1=d1.getYear();
	y2=d2.getYear();

	cout << y1 << " " << y2 << endl;

	m1 = d1.getMonth();
	m2 = d2.getMonth();

	cout << m1 << " " << m2 << endl;

	di1 = d1.getDay();
	di2 = d2.getDay();

	cout << di1 << " " << di2 << endl;
	
	string day1, day2;
	day1 = d1.getDate(); 
	day2 = d2.getDate();

	d1.show();
	cout << endl;
	d2.show();

	bool boolean;

	boolean = d1.isAfter(d2);
	cout << endl << boolean << endl;

	boolean= d1.isBefore(d2);
	cout << boolean << endl;

	boolean = d1.isEqualTo(d2);
	cout << boolean << endl;

	boolean = d1.isNotEqualTo(d2);
	cout << boolean << endl;

	system("pause");
    return 0;
}

