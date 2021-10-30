#include<iostream>
#include "Date.h"
#include "Order.h"
using namespace std;



Order::Date::Date(int DD, int MM, int YY) : dd(DD), mm(MM), yy(YY) {
	if (YY > 99)
		throw "YY should lie between 00-99\n";
}
		
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
