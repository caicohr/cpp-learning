#include <sstream>

using namespace std;

class Dispenser {

public:
	Dispenser();
	//Dispenser(string name, float price, int quantity);
	string getCurrentInventory();
	void sellItem(int i);
	string getItemName(int i);
	int getQuantity(int i);
	int getSelectionSize();
	float getItemPrice(int i);
	bool hasInv();
private:
	struct item{
		string name;
		float price;
		int quantity;
	};
	item inv[5];
	
};

