#include<iostream>
#include<string>
#include "Order.h"
using namespace std;

#ifndef DATE_H
#define DATE_H

class Order::Date {
	public:
		int dd, mm, yy;
		
		Date(int DD, int MM, int YY);
		string to_string() const; 
		
		//friend ostream& operator<<(ostream& out, const Date& date);
};

ostream& operator<<(ostream& out, const Order::Date* date);

#endif
