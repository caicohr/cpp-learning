#include <iostream>
#include <iomanip>

#include "dispenser.h"
#include "register.h"

using namespace std;

int main()
{
	Dispenser inv;
	int Choice;
	float Pay;
	float needToPay;
	float change;
	
	/*
	Dispenser Chips("Chips",2.50,10);
	Dispenser Candy("Candy",1.25,10);
	Dispenser Gum("Gum",1.00,10);
	Dispenser Soda("Soda",1.5,10);
	Dispenser Water("Water",1.25,10);
	*/

	cout << "Welcome to the vending machine!" << endl;
	Register cashier(50);;

	while (inv.hasInv()) {
		cout << inv.getCurrentInventory();
		cout << "Make your selection (0 to exit) : ";
		cin >> Choice;
		//cout << "You chose: " << Choice << endl;
		Choice = Choice -1;
		
		if (Choice == -1)
		{
			cout << "Good Bye!"<<endl;
				return -1;
		}
		else if (Choice >= inv.getSelectionSize() || Choice < 0) {
			cout << "Invalid Selection\n";
		}
		else
		{
			Pay = 0;
			needToPay = inv.getItemPrice(Choice);
			//cout << "You need to pay "<< inv.getItemPrice(Choice)<<endl;
			if (inv.getQuantity(Choice) > 0) {//nu adda pay
				//cout << "Insert $" << needToPay <<": ";
				//cin >> Pay;
				//cout << "You inserted " << Pay << endl;
				while (needToPay > Pay) {//kurang
					
					cout << "Insert $" << setprecision(2)<<fixed <<needToPay <<": ";
					cin >> Pay;
					//needToPay = needToPay - Pay;
					//needToPay - Pay;
					if (Pay < 0) {
						cout << "You're kidding, right?" << endl;
						Pay = 0;
						needToPay = inv.getItemPrice(Choice);
					}
					else if (needToPay > Pay || Pay == 0) {//kurang
						needToPay = needToPay - Pay;
						Pay = 0;
						//cout <<"Insert $" << needToPay <<": ";
						//cin >> Pay;
					}
					else if (needToPay < Pay) {//give the change
						change = Pay - needToPay;
						cout << inv.getItemName(Choice) << " dispensed" << endl;
						cout << "Returning $" <<setprecision(2)<<fixed << change << endl;
						float addToCashier = inv.getItemPrice(Choice);
						cashier.addMoney(addToCashier);
						cashier.getMoney();
						//Pay = ;
						inv.sellItem(Choice);
					}
					else if (needToPay == Pay) {
						cout << inv.getItemName(Choice) << " dispensed" << endl;
						float addToCashier = inv.getItemPrice(Choice);
						cashier.addMoney(addToCashier);
						cashier.getMoney();
						inv.sellItem(Choice);
					}
					
				}
			}
			else {
				cout << "\nNo " << inv.getItemName(Choice) << "left\n";
			}
		}
	}

	printf("\n***You ran out***\n");

	system("pause");
}