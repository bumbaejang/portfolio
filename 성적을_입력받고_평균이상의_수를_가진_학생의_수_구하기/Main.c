#include <stdio.h>

int arraysum(int n, int a[]){
	int sum = 0;
	int i = 0;

	for(i=0;i<n;i++){
		sum += a[i];
	}
	return sum;
}

int main() {
	int n, i, sum, avg;
	int count = 0;
	int score[100] = {0};
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &score[i]);
	}
	
	sum = arraysum(n, score);
	avg = sum / n;
	
	if(((avg*10) % 10) > 0){
		avg++;
	}
	
	for(i=0;i<n;i++){
		if(score[i] >= avg){
			count++;
		}
	}
	
	printf("%d", count);
	return 0;
}
