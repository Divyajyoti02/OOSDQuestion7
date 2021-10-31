#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include "Customer.h"
#include "Order.h"
#include "Date.h"
using namespace std;

		
Order::Order(Customer* cust, int dd, int mm, int yy) : status(false), customer(cust) {date = new Date(dd, mm, yy);}

Order::~Order() {delete date;}
		
void Order::process() {status = true;}
