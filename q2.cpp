#include <iostream>
#include <string>
using namespace std;

class bankSystem{
private:
string accNo;
string holderName;
float currentBalance;  
public:

bankSystem(string a, string h, float c) : accNo(a) , holderName(h) , currentBalance(c){
cout << "Account Created!\n ";
}

void moneyDeposit(float amount){
if(amount > 0.0){
currentBalance += amount;
}else{
cout << "Invalid Amount Entered!";
}
}


void moneyWithdraw(float amount) {
   if (amount <= 0.0) {
       cout << "Error: Withdrawal amount must be greater than zero." << endl;
   }
   else if (amount > currentBalance) {
       cout << "Error: Insufficient funds! Transaction cancelled." << endl;
   }
   else {
       currentBalance -= amount;
       cout << "Transaction Successful! $" << amount << " withdrawn." << endl;
   }
}

float checkBalance(){
return currentBalance;
}

void displayInfo(){
cout << "Account No: " << accNo << endl;
cout << "Account Holder Name: " << holderName << endl;
cout << "Current Balance : " << currentBalance << endl;
}

};

int main(){

string accNo, holderName;
float currentBalance;

cout << "Enter the Account No: ";
getline(cin, accNo);

cout << "Enter the Account Holder Name: ";
getline(cin, holderName);

cout << "Enter the Current Balance of your Account :";
cin >> currentBalance;
cin.ignore();

bankSystem b1(accNo, holderName, currentBalance);

float Amount, wAmount;

cout << "Enter the Amount you have to Desposit: ";
cin >> Amount;
cin.ignore();

b1.moneyDeposit(Amount);

cout << "The Current Balance is: " << b1.checkBalance() << endl;

b1.displayInfo();

cout << "Enter the Amount you have to Withdraw: ";
cin >> wAmount;
cin.ignore();

b1.moneyWithdraw(wAmount);

cout << "The Current Balance is: " << b1.checkBalance() << endl;

b1.displayInfo();

return 0;
}