#include <iostream>
#include <string>
#include <iomanip>

#include "dispenser.h"

using namespace std;
/*
Dispenser::Dispenser(string n, float p, int q){
	name = n;
	price = p;
	quantity = q;
}
*/
Dispenser::Dispenser() {
	inv[0].name = "Chips";
	inv[0].price = 2.50;
	inv[0].quantity = 10;

	inv[1].name = "Candy";
	inv[1].price = 1.25;
	inv[1].quantity = 10;

	inv[2].name = "Gum";
	inv[2].price = 1.00;
	inv[2].quantity = 10;
	
	inv[3].name = "Soda";
	inv[3].price = 1.50;
	inv[3].quantity = 10;
	
	inv[4].name = "Water";
	inv[4].price = 1.25;
	inv[4].quantity = 10;
	
}


string Dispenser::getCurrentInventory() {
	ostringstream oss;
	string str;

	for (int i = 0; i < (sizeof(inv) / sizeof(*inv)); i++) {
		oss << (i + 1) << ": " << inv[i].name << ": $" << setprecision(2)<<fixed <<inv[i].price << " (" << inv[i].quantity << ")" << endl;
	}
	return str = oss.str();;
}

void Dispenser::sellItem(int i) {
	inv[i].quantity--;
}

string Dispenser::getItemName(int i) {
	return inv[i].name;
}

float Dispenser::getItemPrice(int i) {
	return inv[i].price;
}

int Dispenser::getQuantity(int i) {
	try {
		return inv[i].quantity;
	}
	catch (exception ex) {
		return -1;
	}
}

int Dispenser::getSelectionSize() {
	return (sizeof(inv) / sizeof(*inv));
}

bool Dispenser::hasInv() {
	int val = 0;
	for (int i = 0; i < (sizeof(inv) / sizeof(*inv)); i++) {
		val += inv[i].quantity;
	}
	if (val > 0) {

		return 1;
	}
	else {
		return 0;
	}
}