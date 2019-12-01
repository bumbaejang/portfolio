#include <stdio.h>
int electronic_charge(int month, int used_e);
int self_round(float num);
	
int main() {
	int i;
	int month, user;
	int max_used_e, min_used_e;
	float average_used_e;
	int average_e_charge;
	int used_e[1000] = {0};
	int e_charge[1000] = {0};
	
	
	scanf("%d %d", &month, &user);
	
	for(i=0;i<user;i++){
		scanf("%d", &used_e[i]);
		e_charge[i] = electronic_charge(month, used_e[i]);
	}
	
	max_used_e = used_e[0];
	min_used_e = used_e[0];
	
	for(i=0;i<user;i++){
		average_used_e += used_e[i];
		average_e_charge += e_charge[i];
		if(max_used_e < used_e[i]){
			max_used_e = used_e[i];
		}
		if(min_used_e > used_e[i]){
			min_used_e = used_e[i];
		}
	}
	
	average_used_e = average_used_e / user;
	average_e_charge = average_e_charge / user;
	
	printf("%d %d\n", min_used_e, max_used_e);
	printf("%.1f %d\n", average_used_e, average_e_charge);
	return 0;
}

int self_round(float num){
	int n_num;
	
	n_num = (num * 10);
	
	if((n_num % 10) >= 5){
		n_num = (int)num + 1;
	}else{
		n_num = (int)num;
	}
	
	return n_num;
}

int electronic_charge(int month, int used_e)
{
	int money_for_e;
	int res;
	int ext;
	
	if(used_e <= 200)
		money_for_e = (int)(910 + 93.3 * used_e);
	else if(used_e > 200 && used_e <= 400)
		money_for_e = (int)(1600 + 200 * 93.3 + 187.9 * (used_e - 200));
	else if(used_e > 400 && used_e <= 1000)
		money_for_e = (int)(7300 + 200 * 93.3 + 200 * 187.9 + 280.6 * (used_e - 400));
	else
		if(month == 7 || month == 8 || month == 12 || month == 1 || month == 2)
			money_for_e = (int)(7300 + 200 * 93.3 + 200 * 187.9 + 280.6 * 600 + 709.5 * (used_e - 1000));
		else
			money_for_e = (int)(7300 + 200 * 93.3 + 200 * 187.9 + 280.6 * (used_e - 400));
	
	ext = (int)(money_for_e * 0.037);
	res = money_for_e + self_round(money_for_e * 0.1) + ext;
	if((res % 10) >= 5){
		res = res - (res % 10) + 10;
	}else{
		res = res - (res % 10);
	}
	return res;
}