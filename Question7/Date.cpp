#include<iostream>
#include<string>
#include "Date.h"
#include "Order.h"
using namespace std;



Order::Date::Date(int DD, int MM, int YY) : dd(DD), mm(MM), yy(YY) {}
		
ostream& operator<<(ostream& out, const Order::Date* date) {return out << date->to_string();}

string Order::Date::to_string() const {
	string s("");
	s.append(std::to_string(dd));
	s.append("/");
	s.append(std::to_string(mm));
	s.append("/");
	s.append(std::to_string(yy));
	return s;
}
