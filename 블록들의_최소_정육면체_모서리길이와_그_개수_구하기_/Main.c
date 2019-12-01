#include <stdio.h>
int GCD(int a, int b);
int LCM(int a, int b);
 
int main() {
	int x, y, z;
	int lcm1, lcm2, lcm;
	unsigned int brick;
	
	scanf("%d %d %d", &x, &y, &z);
	
	lcm1 = LCM(x, y);
	lcm2 = LCM(x, z);
	lcm = LCM(lcm1, lcm2);
	
	brick = (lcm / x) * (lcm / y) * (lcm / z);
	
	printf("%d %u", lcm, brick);
	
	return 0;
}
 
int GCD(int a, int b)
{
	int tmp;
	
	if(a < b){
		tmp = a;
		a = b;
		b = tmp;
	}
	
	while(b != 0){
		tmp = a % b;
		a = b;
		b = tmp;
	}
	
	return a;
}
 
int LCM(int a, int b)
{
	int d;
	int c = GCD(a, b);
	d = (a * b) / c;
	
	return d;
}