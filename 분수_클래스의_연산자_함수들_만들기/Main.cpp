#include <iostream>
#include <math.h>
using namespace std;

class Fraction{
	private:
	int numerator;
	int denominator;
	int gcd(int a, int b){
		int r;
		while(a % b != 0){
			r = a % b;
			a = b;
			b = r;
		}
		return b;
	}
	
	public:
	Fraction(){}
	
	Fraction(int n, int d){
		numerator = n;
		denominator = d;
	}
	
	void setFraction(int n, int d){
		numerator = n;
		denominator = d;
	}
	
	int getnumerator(){
		return numerator;
	}
	
	int getdenominator(){
		return denominator;
	}
	
	friend istream& operator>>(istream& cin, Fraction& F);
	friend ostream& operator<<(ostream& cout, Fraction& F);
	friend Fraction operator++(Fraction& F);
	friend Fraction operator*(int i, Fraction F);
	
	void print(){
		if(denominator < 0){
			numerator *= -1;
			denominator *= -1;
		}
		cout << numerator << "/" << denominator << endl;
	}
	
	int reduce(){
		int gcdNumDen;
		if(numerator == 0 || denominator == 0)
			return 0;
		gcdNumDen = gcd(numerator, denominator);
		numerator = numerator / gcdNumDen;
		denominator = denominator / gcdNumDen;
		return 0;
	}
	
	Fraction operator+(Fraction F);
	Fraction operator-(Fraction F);
	Fraction operator*(int i); 
};

Fraction Fraction::operator+(Fraction F){
	int predenominator = denominator;
	int den, numer;
	den = denominator * F.denominator / gcd(denominator, F.denominator);
	numer = numerator * (den / predenominator) + F.numerator * (den / F.denominator);
	Fraction result = {numer, den};
	result.reduce();
	return result;
}

Fraction Fraction::operator-(Fraction F){
	int predenominator = denominator;
	int den, numer;
	den = denominator * F.denominator / gcd(denominator, F.denominator);
	numer = numerator * (den / predenominator) - F.numerator * (den / F.denominator);
	Fraction result = {numer, den};
	result.reduce();
	return result;
}

Fraction Fraction::operator*(int i){
	int den, numer;
	den = denominator;
	numer = numerator * i;
	Fraction result = {numer, den};
	result.reduce();
	return result;
}

Fraction operator*(int i, Fraction F){
	F.numerator = F.numerator * i;
	F.reduce();
	return F;
}

istream& operator>>(istream& cin, Fraction& F){
	int n, d;
	cin >> n >> d;
	F.numerator = n;
	F.denominator = d;
	return cin;
}

ostream& operator<<(ostream& cout, Fraction& F){
	cout << F.numerator << "/" << F.denominator;
	return cout;
}

Fraction operator++(Fraction& F){
	F.numerator = F.numerator + F.denominator;
	F.reduce();
	return F;
}

int main()
{
	Fraction f1, f2;
	Fraction sumF, subF, df2, fd2;
	
	cin >> f1 >> f2;
	f1.reduce();
	f2.reduce();
	cout << f1 << endl << f2 << endl;
	sumF = f1 + f2;
	subF = f1 - f2;
	cout << sumF << endl << subF << endl;
	++f1;
	df2 = 2 * f2;
	fd2 = f2 * 2;
	cout << f1 << endl << df2 << endl << fd2 << endl;
	
	return 0;
}