#include<string>
#include "Company.h"
#include "Person.h"
#include "OrderList.h"
using namespace std;

#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

class CustomerList {
	private:
		unsigned int choice, choice2;
		vector<Company*> cList;
		vector<Person*> pList;
		string dString;
		
		void viewCompanies();
		void viewPersons();
		
	public:
		void createCompany();
		void deleteCompany(OrderList& ol);
		void updateCompany();
		void createPerson();
		void deletePerson(OrderList& ol);
		void updatePerson();
		void placeOrder(OrderList& ol);
		void view();
		void viewPerCustomer(OrderList& ol);
		void deleteOrder(OrderList& ol);
};

#endif
