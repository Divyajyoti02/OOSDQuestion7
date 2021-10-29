#include<cmath>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
#include<iostream>
using namespace std;




string precisionPrint(float num, unsigned int prec) {
	stringstream ss;
	ss << fixed << setprecision(prec) << num;
	return ss.str();
}




class item {
	public:
		unsigned int id, qty, amount;
		float discount;


		item(unsigned int Id, unsigned int Qty, unsigned int Amount, float Discount = 0.0) : id(Id), qty(Qty), amount(Amount), discount(Discount) {
			if (Discount < 0)
				throw "Discount can not be negative\n";
			else if (Discount > 100)
				throw "Discount can not be greater than 100\n";
		}
				
		float netPrice() {return round(qty * amount * (100.00 - discount)) / 100.00;}
};

class itemList {
	private:
		vector<item> iList;



	public:
		float total;

		
		itemList() {total = 0;}
		
		void addItem(unsigned int Id, unsigned int Qty, unsigned int Amount, float Discount = 0.0) {
			item it = item(Id, Qty, Amount, Discount);
			iList.push_back(it);
			total += it.netPrice();
		}
		
		void viewList() {
			cout << "ID\tQty\tAmount\tDiscount\tNetPrice" << endl;
			for (auto item: iList) {cout << item.id << '\t' << item.qty << '\t' << item.amount << '\t' << item.discount << "\t\t" << precisionPrint(item.netPrice(), 2) << endl;}
		}
		
		void getTotal() {cout << "Total=" << precisionPrint(total, 2) << endl;}
};

int main() {
	itemList lst = itemList();
	lst.addItem(1, 3, 5);
	lst.addItem(2, 10, 9, 0);
	lst.addItem(3, 4, 10, 2.5);
	lst.viewList();
	lst.getTotal();
	return 0;
}
