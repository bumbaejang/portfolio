#include <stdio.h>
int arraymax(int n, int a[]){
	int i;
	int max = 0;
	int ind_max = 0;
	
	for(i=0;i<n;i++){
		if(a[i] > max){
			max = a[i];
			ind_max = i;
		}
	}
	return ind_max;
}

int main() {
	int A[100] = {0};
	int n, i;
	int ind_max, tmp;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
	
	for(i=n-1;i>0;i--){
		ind_max = arraymax(i+1, A);
		tmp = A[i];
		A[i] = A[ind_max];
		A[ind_max] = tmp;
	}
	
	for(i=0;i<n;i++){
		printf("%d ", A[i]);
	}
	
	return 0;
}
