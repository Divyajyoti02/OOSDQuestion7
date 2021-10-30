#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include "Customer.h"
using namespace std;

#ifndef ORDER_H
#define ORDER_H

class Order {
	private:
		const Customer* customer;
		
	public:
		bool status;
		
		class Date {
			public:
				int dd, yy, mm;
		
				Date(int DD, int MM, int YY);
		};
		
		Date date;
		
		Order(Customer* cust, int dd, int mm, int yy);
		
		void process();

		friend ostream& operator<<(ostream& out, const Date& date);
};

ostream& operator<<(ostream& out, const Order::Date& date);

#endif
