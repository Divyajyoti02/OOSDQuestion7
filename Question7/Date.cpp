#include<iostream>
#include "Date.h"
#include "Order.h"
using namespace std;



Order::Date::Date(int DD, int MM, int YY) : dd(DD), mm(MM), yy(YY) {}
		
ostream& operator<<(ostream& out, const Order::Date& date) {
	out << date.dd << '/' << date.mm << '/' << date.yy;
	return out;
}
