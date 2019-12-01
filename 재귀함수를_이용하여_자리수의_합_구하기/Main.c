#include <stdio.h>
int digit_sum(int n){
	
	if(n == 0){
		return 0;
	}else{
		return digit_sum(n/10) + (n%10);
	}
}

int main() {
	int n;
	
	scanf("%d", &n);
	printf("%d", digit_sum(n));
	return 0;
}
