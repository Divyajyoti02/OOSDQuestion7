#include<iostream>
#include "Date.h"
using namespace std;



Date::Date(unsigned int DD, enum Month MM, unsigned int YY) : dd(DD), mm(MM), yy(2000 + YY) {
	if (YY > 99)
		throw "YY should lie between 00-99\n";
}
		
ostream& operator<<(ostream& out, const Date& date) {
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
