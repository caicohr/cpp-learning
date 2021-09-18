#include <iostream>
#include <string>

using namespace std;

class Register {
    
public:
    Register(float balance);
    void getMoney();
    void addMoney(float plus);
    void deductMoney(float minus);
private:
    float balance;
    
};