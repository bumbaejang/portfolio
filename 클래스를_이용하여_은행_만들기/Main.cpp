#include <iostream>
#include <string>
#include <string.h>
using namespace std;
 
class BankAccount{
	private:
	int accountNumber;
  string owner;
	int balance;
	int pinNumber;
 
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
	void setAN(int n){
		accountNumber = n;
	}
	void setOW(string n){
		owner = n;
	}
	void setBA(int n){
		balance = n;
	}
	void setPN(int n){
		pinNumber = n;
	}
	string getOW(){
		return owner;
	}
	int getAN(){
		return accountNumber;
	}
};

BankAccount::BankAccount(){
	owner = "me";
	balance = 0;
	pinNumber = 1234;
	accountNumber = 11111;
}

BankAccount::BankAccount(string owner1, int pinNum, int ini_balance){
	owner = owner1;
	balance = ini_balance;
	pinNumber = pinNum;
	accountNumber = 11111;
}
 
BankAccount::BankAccount(string owner1, int pinNum, int ini_balance, int acNum){
	owner = owner1;
	balance = ini_balance;
	pinNumber = pinNum;
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
	if(number == pinNumber)
		return true;
	else{
		cout << "PWD not correct" << endl;
		return false;
	}
}
 
void BankAccount::changePinNumber(int num){
	if(checkPinNumber())
		pinNumber = num;
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
 
class Bank{
	private:
	BankAccount account[100];
	string BankName;
	int last_accountNum;
	int total_userNumber;
	public:
	Bank();
	void newAccount(string ownerName, int pinNum, int ini_balance);
	int getBalance(int accountnum);
	void getAllAccountNumberOfOwner(string name);
	void deposit(int accountNum, int amount);
	void withdraw(int accountNum, int amount);
};
 
Bank::Bank(){
	last_accountNum = 11111;
	total_userNumber = 0;
}
 
void Bank::newAccount(string ownerName, int pinNum, int ini_balance){
	BankAccount newone(ownerName, pinNum, ini_balance, last_accountNum);
	account[total_userNumber] = newone;
	total_userNumber++;
	last_accountNum++;
}
 
int Bank::getBalance(int accountnum){
	int i = 0;
	for(i=0;i<total_userNumber;i++)
		if(account[i].getAccountNumber() == accountnum)
			break;
	return account[i].getBalance();
}
 
void Bank::getAllAccountNumberOfOwner(string name){
	for(int i=0;i<100;i++){
		if(account[i].getOW() == name){
			cout << account[i].getAN();
		}
	}
}
 
void Bank::deposit(int accountNum, int amount){
	account[accountNum-11111].deposit(amount);
}

void Bank::withdraw(int accountNum, int amount){
	account[accountNum-11111].withdraw(amount);
}
 
int main() {
	Bank bk;
	int command = 0;
	while(command != 5){
		cin >> command;
		if(command == 1){
			string name;
			int pwd;
			int startbalance;
			cin >> name >> pwd >> startbalance;
			bk.newAccount(name, pwd, startbalance);
		}else if(command == 2){
			int acNum, gb;
			cin >> acNum;
			gb = bk.getBalance(acNum);
			if(gb != -1)
				cout << gb << endl;
		}else if(command == 3){
			int acNum_d, dAmount;
			cin >> acNum_d >> dAmount;
			bk.deposit(acNum_d, dAmount);
		}else if(command == 4){
			int acNum_w, wAmount;
			cin >> acNum_w >> wAmount;
			bk.withdraw(acNum_w, wAmount);
		}else if(command == 5){
			break;
		}else{
			cout << "error" << endl;
		}
	}
	return 0;
}