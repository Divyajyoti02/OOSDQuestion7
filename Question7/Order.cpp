#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include "Customer.h"
#include "Order.h"
using namespace std;

		
Order::Order(Customer* cust, int dd, int mm, int yy) : status(false), customer(cust) {
	if (mm < 1 || mm > 12) {
		throw "MM should be between 01-12";
	}
	if (yy > 99) {
		throw "YY should lie between 00-99\n";
	}
	date = Date(dd, mm, yy);
}

Order::Date(int DD, int MM, int YY) : dd(DD), mm(MM), yy(YY) {}
		
void Order::process() {status = true;}

ostream& operator<<(ostream& out, const Order::Date& date) {
	if (date.dd < 10)
		out << '0' << date.dd << '/';
	else
		out << date.dd << '/';
	out << date.mm << "/";	
	if (date.yy < 10)
		out << '0' << date.yy;
	else
		out << date.yy;
	return out;
}
