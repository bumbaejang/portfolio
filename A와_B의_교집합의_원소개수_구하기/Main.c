#include <stdio.h>
int isexist(int B[], int nB, int x){
	int j;
	
	for(j=0;j<nB;j++){
		if(B[j] == x){
			return 1;
		}
	}
	return 0;
}

int existcommonx(int A[], int nA, int B[], int nB){
	int i;
	int number_of_AnB = 0;
	
	for(i=0;i<nA;i++){
		if(isexist(B, nB, A[i]) == 1){
			number_of_AnB++;
		}
	}
	
	return number_of_AnB;
}

int main() {
	int A[100] = {0};
	int B[100] = {0};
	int nA, nB, i;
	int number_of_AnB;
	
	scanf("%d \n %d", &nA, &nB);
	
	for(i=0;i<nA;i++){
		scanf("%d", &A[i]);
	}
	
	for(i=0;i<nB;i++){
		scanf("%d", &B[i]);
	}
	
	number_of_AnB = existcommonx(A, nA, B, nB);
	
	printf("%d", number_of_AnB);
	return 0;
}
