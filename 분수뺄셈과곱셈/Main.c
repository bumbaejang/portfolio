#include <stdio.h>
#include <math.h>
 
struct Fraction{
	int numerator; //분자
	int denominator; //분모
};
 
int gcd(int a, int b){ //최대공약수 함수 
	int r;
	while(a % b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}
 
int lcm(int a, int b){ //최소공배수 함수
	int c, d;
	
	c = gcd(a,b);
	d = (a * b) / c;
	return d;
}
 
void print(struct Fraction r){
	
	if(r.denominator < 0){ //결과값이 음수면 분자를 음수로 하기
		r.numerator *= -1;
		r.denominator *= -1;
	}
	printf("%d/%d ", r.numerator, r.denominator);
}
 
struct Fraction reduce(struct Fraction r){ //약분함수
	int gcdNumDen;
	struct Fraction result;
	if(r.numerator == 0 || r.denominator == 0){
		result.numerator = 0;
		result.denominator = 1;
	}else{
		gcdNumDen = gcd(r.numerator, r.denominator);
		result.numerator = r.numerator / gcdNumDen;
		result.denominator = r.denominator / gcdNumDen;
	}
	
	return result;
}
 
struct Fraction sub(struct Fraction r1, struct Fraction r2){ //빼기 함수
	struct Fraction result;
	struct Fraction nr1;
	struct Fraction nr2;
	
	nr1 = reduce(r1);
	nr2 = reduce(r2);
	result.denominator = lcm(nr1.denominator, nr2.denominator);
	result.numerator = nr1.numerator * (result.denominator / nr1.denominator) - nr2.numerator * (result.denominator / nr2.denominator);
	return reduce(result);
}
 
struct Fraction mul(struct Fraction r1, struct Fraction r2){ //곱하기 함수
	struct Fraction result;
	struct Fraction nr1;
	struct Fraction nr2;
	
	nr1 = reduce(r1);
	nr2 = reduce(r2);
	result.denominator = nr1.denominator * nr2.denominator;
	result.numerator = nr1.numerator * nr2.numerator;
	return reduce(result);
}
 
int main() {
	struct Fraction r1, r2, result1, result2;
	scanf("%d %d %d %d", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
	result1 = sub(r1, r2);
	result2 = mul(r1, r2);
	print(result1);
	print(result2);
	
	return 0;
}