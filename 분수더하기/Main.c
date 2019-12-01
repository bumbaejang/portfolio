#include <stdio.h>
#include <math.h>

struct Fraction{
	int numerator; //분자
	int denominator; //분모
};

int gcd(int a, int b){
	int r;
	while(a % b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int lcm(int a, int b){
	int c, d;
	
	c = gcd(a,b);
	d = (a * b) / c;
	return d;
}

void print(struct Fraction r){
	int num, denom;
	
	if(r.denominator < 0){
		r.numerator *= -1;
		r.denominator *= -1;
	}
	printf("%d/%d\n", r.numerator, r.denominator);
}

struct Fraction reduce(struct Fraction r){
	int gcdNumDen;
	struct Fraction result;
	if(r.numerator == 0 || r.denominator == 0)
		return r;
	
	gcdNumDen = gcd(r.numerator, r.denominator);
	result.numerator = r.numerator / gcdNumDen;
	result.denominator = r.denominator / gcdNumDen;
	
	return result;
}

struct Fraction add(struct Fraction r1, struct Fraction r2){
	struct Fraction result;
	result.denominator = lcm(r1.denominator, r2.denominator);
	result.numerator = r1.numerator * (result.denominator / r1.denominator) + r2.numerator * (result.denominator / r2.denominator);
	return reduce(result);
}

int main() {
	struct Fraction r1, r2, result;
	scanf("%d %d %d %d", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
	result = add(r1, r2);
	print(result);
	
	return 0;
}
