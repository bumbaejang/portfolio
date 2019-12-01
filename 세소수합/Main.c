#include <stdio.h>
int is_prime(int k);
 
int main(){
	int n, tmp;
	int i, j;
	int a = 0, b = 0, c = 0, d = 0;
	
	scanf("%d", &n);
	
	for(i=4;i<=n;i++){
		c = n - i;
		if(is_prime(c) == 1){
			for(j=2;j<=i;j++){
				tmp = i - j;
				if((is_prime(tmp) == 1) && (is_prime(j) == 1)){
					b = tmp;
					a = j;
				if((a != 0) && (b != 0) && (c != 0))
					break;
				}
			}
		}
		if((a != 0) && (b != 0) && (c != 0))
			break;
	}
	
	if((a == 0) || (b == 0) || (c == 0)){
		printf("%d", d);
	}else{
		printf("%d %d %d", a, b, c);
	}
	
	return 0;
}
 
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