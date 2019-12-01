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
 
void printUnion(int na, int nb, int studenta[], int studentb[]){ //합집합으로 만들고 오름차순 배열 후 출력 함수
	int studentAll[2000] = {0};
	int studentCount = 0;
	int i,j,ind_max,tmp;
	for(i=0;i<na;i++){
		studentAll[i] = studenta[i];
	}
	for(i=0;i<nb;i++){
		studentAll[i+na] = studentb[i];
	}
	for(i=0;i<na+nb-1;i++){
		for(j=i+1;j<na+nb;j++){
			if(studentAll[i] == studentAll[j]){
				studentAll[i] = 0;
			}
		}
	}
	for(i=na+nb-1;i>0;i--){
		ind_max = arraymax(i+1,studentAll);
		tmp = studentAll[i];
		studentAll[i] = studentAll[ind_max];
		studentAll[ind_max] = tmp;
	}
	for(i=0;i<na+nb;i++){
		if(studentAll[i] != 0){
			studentCount++;
		}
	}
	printf("%d\n", studentCount);
	for(i=0;i<na+nb;i++){
		if(studentAll[i] != 0){
			printf("%d ", studentAll[i]);
		}
	}
}
 
int main(){
	int studentA[1000] = {0};
	int studentB[1000] = {0};
	int nA, nB, i;
	scanf("%d", &nA);
	for(i=0;i<nA;i++){
		scanf("%d", &studentA[i]);
	}
	scanf("%d", &nB);
	for(i=0;i<nB;i++){
		scanf("%d", &studentB[i]);
	}
	printUnion(nA, nB, studentA, studentB);
	return 0;
}