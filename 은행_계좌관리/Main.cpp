#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Date{
	private:
	int year;
	int month;
	int day;

	public:
	Date(){
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d){
		year = y;
		month = m;
		day = d;
	}
	int getYear(){
		return year;
	}
	int getMonth(){
		return month;
	}
	int getDay(){
		return day;
	}
	void setYear(int y){
		year = y;
	}
	void setMonth(int m){
		month = m;
	}
	void setDay(int d){
		day = d;
	}
};

class Account{
	private:
	int accountnumber;
	string owner;
	int balance;
	Date sd;
	
	public:
	Account(){
		accountnumber = 0;
		owner = "none";
		balance = 0;
		sd.setYear(0);
		sd.setMonth(0);
		sd.setDay(0);
	}
	Account(int an, string o, int b, Date c){
		accountnumber = an;
		owner = o;
		balance = b;
		sd.setYear(c.getYear());
		sd.setMonth(c.getMonth());
		sd.setDay(c.getDay());
	}
	int getAccountnumber(){
		return accountnumber;
	}
	string getOwner(){
		return owner;
	}
	int getBalance(){
		return balance;
	}
	Date getSd(){
		return sd;
	}
	void setAccountnumber(int a){
		accountnumber = a;
	}
	void setOwner(string o){
		owner = o;
	}
	void setBalance(int b){
		balance = b;
	}
	void setSd(int y, int m, int d){
		sd.setYear(y);
		sd.setMonth(m);
		sd.setDay(d);
	}
	void add(int amount){
		balance += amount;
	}
	void sub(int amount){
		balance -= amount;
	}
	bool operator<(Account a) const{ //연산자 오버로딩
		return accountnumber < a.accountnumber;
	}
};

class Bank{
	private:
	vector<Account> info;
	 
	public:
	void newAccount(string name, int amount, int y, int m, int d); //신규
	void deposit(int account, int amount); //입금
	void withdraw(int account, int amount); //출금
	void getCreateaccount(int y, int m, int d); //개설날짜조회
	void accountTransfer(int a1, int a2, int amount); //계좌이체
	void getAccountinfo(int account); //계좌번호조회
	void getOwnerinfo(string name); //예금주이름조회
	void deleteAccount(int account); //해지
	void getAllaccount(); //전체계좌조회
};

void Bank::newAccount(string name, int amount, int y, int m, int d){
	static int pin = 11111;
	Date c(y, m ,d);
	Account a(pin, name, amount, c);
	info.push_back(a);
	pin++;
}

void Bank::deposit(int account, int amount){
	int a = 0;
	int n = info.size();
	for(int i=0;i<n;++i){
		if(account == info[i].getAccountnumber()){
			info[i].add(amount);
			a = 1;
			break;
		}
	}
	if(a == 0)
		cout << "error1" << endl;
}

void Bank::withdraw(int account, int amount){
	int a = 0;
	int n = info.size();
	for(int i=0;i<n;++i){
		if(account == info[i].getAccountnumber()){
			if(info[i].getBalance() >= amount){
				info[i].sub(amount);
				a = 1;
				break;
			}else{
				a = 2;
				break;
			}
		}
	}
	if(a == 0)
		cout << "error1" << endl;
	else if(a == 2)
		cout << "error2" << endl;
}

void Bank::getCreateaccount(int y, int m, int d){
	int n = info.size();
	Date c(y, m, d);
	sort(info.begin(), info.end());
	cout << y << "/" << m << "/" << d << " ";
	for(int i=0;i<n;i++){
		if((info[i].getSd().getYear() == y) && (info[i].getSd().getMonth() == m) && (info[i].getSd().getDay() == d))
			cout << info[i].getAccountnumber() << " ";
	}
	cout << endl;
}

void Bank::accountTransfer(int a1, int a2, int amount){
	int m = -1;
	int n = -1;
	int l = info.size();
	for(int i=0;i<l;++i){
		if(info[i].getAccountnumber() == a1)
			m = i;
		if(info[i].getAccountnumber() == a2)
			n = i;
	}
	if((m != -1) && (n != -1)){
		if(info[m].getBalance() >= amount){
			info[m].sub(amount);
			info[n].add(amount);
		}else
			cout << "error2" << endl;
	}else
		cout << "error1" << endl;
}

void Bank::getAccountinfo(int account){
	int a = 0;
	int n = info.size();
	for(int i=0;i<n;++i){
		if(info[i].getAccountnumber() == account){
			cout << info[i].getAccountnumber() << " " << info[i].getOwner() << " " << info[i].getBalance() << " " << info[i].getSd().getYear() << " " << info[i].getSd().getMonth() << " " << info[i].getSd().getDay() << endl;
			a = 1;
			break;
		}
	}
	if(a == 0)
		cout << "error1" << endl;
}

void Bank::getOwnerinfo(string name){
	int a = 0;
	int n = info.size();
	sort(info.begin(), info.end());
	for(int i=0;i<n;++i){
		if(info[i].getOwner() == name){
			cout << info[i].getOwner() << " " << info[i].getAccountnumber() << " " << info[i].getBalance() << " " << info[i].getSd().getYear() << " " << info[i].getSd().getMonth() << " " << info[i].getSd().getDay() << endl;
			a = 1;
		}
	}
	if(a == 0)
		cout << "error3" << endl;
}

void Bank::deleteAccount(int account){
	int a = 0;
	int n = info.size();
	for(int i=0;i<n;++i){
		if(info[i].getAccountnumber() == account){
			info[i].setAccountnumber(info[n-1].getAccountnumber());
			info[i].setOwner(info[n-1].getOwner());
			info[i].setBalance(info[n-1].getBalance());
			info[i].setSd(info[n-1].getSd().getYear(), info[n-1].getSd().getMonth(), info[n-1].getSd().getDay());
			info.pop_back();
			a = 1;
			break;
		}
	}
	if(a == 0)
		cout << "error1" << endl;
}

void Bank::getAllaccount(){
	int n = info.size();
	sort(info.begin(), info.end());
	for(int i=0;i<n;++i){
		cout << info[i].getAccountnumber() << " " << info[i].getOwner() << " " << info[i].getBalance() << " " << info[i].getSd().getYear() << " " << info[i].getSd().getMonth() << " " << info[i].getSd().getDay() << endl;
	}
}

int main(){
	Bank bnk;
	string command;
	
	while (1){
		cin >> command;
		if(command == "신규"){
			string n;
			int am, y, m, d;
			cin >> n >> am >> y >> m >> d;
			bnk.newAccount(n, am, y, m, d);
		}
		else if(command == "입금"){
			int ac, am;
			cin >> ac >> am;
			bnk.deposit(ac, am);
		}
		else if(command == "출금"){
			int ac, am;
			cin >> ac >> am;
			bnk.withdraw(ac, am);
		}
		else if(command == "개설날짜조회"){
			int y, m, d;
			cin >> y >> m >> d;
			bnk.getCreateaccount(y, m, d);
		}
		else if(command == "계좌이체"){
			int a1, a2, am;
			cin >> a1 >> a2 >> am;
			bnk.accountTransfer(a1, a2, am);
		}
		else if(command == "계좌번호조회"){
			int ac;
			cin >> ac;
			bnk.getAccountinfo(ac);
		}
		else if(command == "예금주이름조회"){
			string n;
			cin >> n;
			bnk.getOwnerinfo(n);
		}
		else if(command == "해지"){
			int ac;
			cin >> ac;
			bnk.deleteAccount(ac);
		}
		else if(command == "전체계좌조회"){
			bnk.getAllaccount();
		}
		else if(command == "종료"){
			break;
		}
	}
	
 	return 0;
}