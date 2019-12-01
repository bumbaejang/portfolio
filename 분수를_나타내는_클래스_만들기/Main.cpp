#include <iostream>
using namespace std;

class Fraction{
	private:
	int numerator; //분자
	int denominator; //분모
	public:
	Fraction();
	Fraction(int x1, int y1);
	int gcd(int a, int b);
	int lcm(int a, int b);
	void reduce();
	Fraction add(Fraction f);
	Fraction sub(Fraction f);
	Fraction mult(Fraction f);
	Fraction div(Fraction f);
	void print();
};
Fraction::Fraction() {}
Fraction::Fraction(int x1, int y1){
	numerator = x1;
	denominator = y1;
}

int Fraction::gcd(int a, int b){
	int r;
	while(a % b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int Fraction::lcm(int a, int b){
	int c, d;
	c = gcd(a,b);
	d = (a * b) / c;
	return d;
}

void Fraction::reduce(){
	int gcdNumDen;
	if(numerator == 0 || denominator == 0){
		numerator = 0;
		denominator = 1;
	}else{
		gcdNumDen = gcd(numerator, denominator);
		numerator = numerator / gcdNumDen;
		denominator = denominator / gcdNumDen;
	}
}

Fraction Fraction::add(Fraction f){
	Fraction result;

	result.denominator = lcm(denominator, f.denominator);
	result.numerator = numerator * (result.denominator / denominator) + f.numerator * (result.denominator / f.denominator);
	result.reduce();
	return result;
}

Fraction Fraction::sub(Fraction f){
	Fraction result;

	result.denominator = lcm(denominator, f.denominator);
	result.numerator = numerator * (result.denominator / denominator) - f.numerator * (result.denominator / f.denominator);
	result.reduce();
	return result;
}

Fraction Fraction::mult(Fraction f){
	Fraction result;

	result.denominator = denominator * f.denominator;
	result.numerator = numerator * f.numerator;
	result.reduce();
	return result;
}

Fraction Fraction::div(Fraction f){
	Fraction result;

	result.denominator = denominator * f.numerator;
	result.numerator = numerator * f.denominator;
	result.reduce();
	return result;
}

void Fraction::print(){
	if(denominator < 0){ //결과값이 음수면 분자를 음수로 하기
		numerator *= -1;
		denominator *= -1;
	}
	cout << numerator << "/" << denominator << endl; 
}

int main() {
	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	Fraction f1 = {x, y};
	Fraction f2 = {x1, y1};
	f1.add(f2).print();
	f1.sub(f2).print();
	f1.mult(f2).print();
	f1.div(f2).print();
	
	return 0;
}