#include <stdio.h>
int main() {
	int a, b;
	int tmp;
	int A, B;
	
	scanf("%d %d", &a, &b);
	A = a;
	B = b;
	
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
	
	b = (A*B) / a;
	
	printf("%d", b);
	return 0;
}
