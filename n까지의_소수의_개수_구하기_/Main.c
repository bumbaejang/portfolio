#include <stdio.h>
#include <stdlib.h>

int is_prime(int k){
	int i = 2;
	while(i*i <= k){
		if(k%i == 0)
			return 0;
		
		else
			i++;
	}
	return 1;
}

int count(int n){
	int i;
	int count = 0;
	
	for(i=2;i<=n;i++){
		if(is_prime(i) == 1)
			count++;
	}
	
	return count;
}
int main() {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", count(n));
	
	return 0;
}
