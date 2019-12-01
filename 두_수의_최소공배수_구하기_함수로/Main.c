#include <stdio.h>
int GCD(int a, int b);
int LCM(int a, int b);

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	printf("%d", LCM(a, b));
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