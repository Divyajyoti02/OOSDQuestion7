#include<string>
#include<vector>
#include "Customer.h"
#include "Order.h"
using namespace std;


Customer::Customer(string Address[3], string Phone) : phone(Phone) {for (int i = 0; i < 3; Customer::address[i++] = Address[i]);}

void Customer::addOrder(int DD, int MM, int YY) {
	Order order = Order(this, DD, MM, YY);
	orderLst.push_back(&order);
}
