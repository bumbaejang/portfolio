#include <stdio.h>
 
struct Fraction{
	int numerator;   //분자
	int denominator; //분모
};
 
struct Point{
	struct Fraction x, y;
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
	result.denominator = lcm(r1.denominator, r2.denominator);
	result.numerator = r1.numerator * (result.denominator / r1.denominator) - r2.numerator * (result.denominator / r2.denominator);
	return reduce(result);
}
 
struct Fraction mul(struct Fraction r1, struct Fraction r2){ //곱하기 함수
	struct Fraction result;
	result.denominator = r1.denominator * r2.denominator;
	result.numerator = r1.numerator * r2.numerator;
	return reduce(result);
}
 
int xComparison(struct Fraction p1, struct Point p2){ //x좌표 비교
	struct Fraction result;
	result = sub(p1,p2.x);
	
	if((result.numerator < 0) || (result.denominator < 0))
		return 1;
	else
		return -1;
}
 
int yComparison(struct Fraction p1, struct Point p2){ //y좌표 비교
	struct Fraction result;
	result = sub(p1,p2.y);
	
	if((result.numerator < 0) || (result.denominator < 0))
		return 1;
	else
		return -1;
}
 
int main(){
	int n, i;
	struct Point p[1000] = {0};
	struct Fraction maxX, maxY, minX, minY;
	struct Fraction r1, r2, result;
	
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d", &p[i].x.numerator, &p[i].x.denominator, &p[i].y.numerator, &p[i].y.denominator);
	}
	
	maxX = p[0].x;
	minX = p[0].x;
	maxY = p[0].y;
	minY = p[0].y;
	
	for(i=1;i<n;i++){
		if(xComparison(maxX,p[i]) == 1){
			maxX = p[i].x;
		}
		if(xComparison(minX,p[i]) == -1){
			minX = p[i].x;
		}
		if(yComparison(maxY,p[i]) == 1){
			maxY = p[i].y;
		}
		if(yComparison(minY,p[i]) == -1){
			minY = p[i].y;
		}
	}
	
	r1 = sub(maxX, minX);
	r2 = sub(maxY, minY);
	result = mul(r1, r2);
	
	print(result);
	
	return 0;
}
