#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include "Customer.h"
#include "Order.h"
#include "Date.h"
using namespace std;

		
Order::Order(const Customer* cust, int dd, int mm, int yy) : status(false), customer(cust) {*date = Date(dd, mm, yy);}
		
void Order::process() {status = true;}
