#include <iostream>
#include <string>
#include <string.h>
#define ini_accountNum 11111 
using namespace std;
 
class BankAccount{
	private:
	int accountNumber;
  string owner;
	int balance;
	int PinNumber;
 
	public:
	BankAccount();
	BankAccount(string owner1, int pinNum, int ini_balance);
	BankAccount(string owner1, int pinNum, int ini_balance, int acNum);
	void setOwner(string name);
	string getOwner();
	int getAccountNumber();
	void changePinNumber(int num);
	bool checkPinNumber();
	int getBalance();
	void deposit(int amount);
	void withdraw(int amount);
	void print();
};
 
BankAccount::BankAccount(string owner1, int pinNum, int ini_balance){
	owner = owner1;
	balance = ini_balance;
	PinNumber = pinNum;
	accountNumber = ini_accountNum;
}

BankAccount::BankAccount(string owner1, int pinNum, int ini_balance, int acNum){
	owner = owner1;
	balance = ini_balance;
	PinNumber = pinNum;
	accountNumber = acNum;
}
 
void BankAccount::setOwner(string name){
	owner = name;
}
 
string BankAccount::getOwner(){
	return owner;
}
 
bool BankAccount::checkPinNumber(){
	int number;
	cin >> number;
	if(number == PinNumber)
		return true;
	else{
		cout << "PWD not correct" << endl;
		return false;
	}
}
 
void BankAccount::changePinNumber(int num){
	if(checkPinNumber())
		PinNumber = num;
}
 
int BankAccount::getAccountNumber(){
	return accountNumber;
}
 
int BankAccount::getBalance(){
	if(checkPinNumber())
		return balance;
	else
		return -1;
}
 
void BankAccount::deposit(int amount){
	balance += amount;
}
 
void BankAccount::withdraw(int amount){
	if(checkPinNumber()){
		if(balance >= amount)
			balance -= amount;
		else
			cout << "잔액부족" << endl;
	}
}
 
void BankAccount::print(){
	cout << "owner : " << owner << endl << "accountNumber : " << accountNumber << endl << "balance : " << balance << endl;
}
 
int main()
{
	string name;
	int pwd;
	int startbalance;
	int amount;
	int n_pwd;
	int gb;
	cin >> name >> pwd >> startbalance;
	BankAccount account01(name, pwd, startbalance);
	int command = 0;
	while(command != 5){
		cin >> command;
		if(command == 1){
			gb = account01.getBalance();
			if(gb != -1)
				cout << gb;
		}else if(command == 2){
			cin >> amount;
			account01.deposit(amount);
		}else if(command == 3){
			cin >> amount;
			account01.withdraw(amount);
		}else if(command == 4){
			cin >> n_pwd;
			account01.changePinNumber(n_pwd);
		}else if(command == 5){
			break;
		}else
			cout << "error" << endl;
	}
 
	return 0;
}