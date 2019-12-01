#include <stdio.h>

 struct student{
	int num;
	char name[16];
	int score;
	char grade;
};

int arrayscore(int n, struct student s[]){ //성적 오름차순 함수
	int i;
	int max = 0;
	int ind_max = 0;
	
	for(i=0;i<n;i++){
		if(s[i].score > max){
			max = s[i].score;
			ind_max = i;
		}
	}
	return ind_max;
}

int arraynum(int n, struct student s[]){ //학번 오름차순 함수
	int i;
	int max = 0;
	int ind_max = 0;
	
	for(i=0;i<n;i++){
		if(s[i].num > max){
			max = s[i].num;
			ind_max = i;
		}
	}
	return ind_max;
}

void printAll(int n, struct student s[]){ //학점계산 & 학번 오름차순 출력
	int i;
	int ind_max = 0;
	int count = 0;
	struct student tmp;
	
	for(i=n-1;i>0;i--){
		ind_max = arrayscore(i+1, s);
		tmp = s[i];
		s[i] = s[ind_max];
		s[ind_max] = tmp;
	}
	
	for(i=n-1;i>=0;i--){
		if(s[i].score == s[i+1].score){
			s[i].grade = s[i+1].grade;
		}else{
			if(count < (n * 3) / 10){
				s[i].grade = 'A';
			}else if(count < (n * 65) / 100){
				s[i].grade = 'B';
			}else if(count < (n * 9) / 10){
				s[i].grade = 'C';
			}else{
				s[i].grade = 'D';
			}
		}
		count++;
	}
	
	for(i=n-1;i>0;i--){
		ind_max = arraynum(i+1, s);
		tmp = s[i];
		s[i] = s[ind_max];
		s[ind_max] = tmp;
	}
	
	for(i=0;i<n;i++){
		printf("%d %s %d %c\n", s[i].num, s[i].name, s[i].score, s[i].grade);
	}
}

int main(){
	int n,i;
	struct student s[100] = {0};
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d %s %d", &s[i].num, s[i].name, &s[i].score);
	}
	
	printAll(n, s);
	
	return 0;
} 
