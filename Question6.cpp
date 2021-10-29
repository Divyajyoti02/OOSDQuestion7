#include<iostream>
using namespace std;



class Animal {
	public:
		void print() {cout << "Animal" << endl;}
};


class Wolf : public Animal {
	public:
		void print() {cout << "Wolf" << endl;}
};


class OtherAnimal : public Animal {
	public:
		void print() {cout << "Other Animal" << endl;}
};


class Fish : public Animal {
	public:
		void print() {cout << "Fish" << endl;}
};


class GoldFish : public Fish {
	public:
		void print() {cout << "Gold Fish" << endl;}
};



int main() {
	Animal a = Animal();
	a.print();
	Wolf w = Wolf();
	w.print();
	OtherAnimal oa = OtherAnimal();
	oa.print();
	Fish f = Fish();
	f.print();
	GoldFish gf = GoldFish();
	gf.print();
	return 0;
}
