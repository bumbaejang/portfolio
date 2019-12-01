#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int electronic_charge(int month, int used_e);

int main() {
	int used_e, month;
	
	scanf("%d", &month);
	scanf("%d", &used_e);

	printf("%d\n", electronic_charge(month, used_e));
	return 0;
}

int electronic_charge(int month, int used_e)
{
	int money_for_e;
	int res;
	int ext;
	
	if(used_e <= 200)
		money_for_e = floor(910 + 93.3 * used_e);
	else if(used_e > 200 && used_e <= 400)
		money_for_e = floor(1600 + 200 * 93.3 + 187.9 * (used_e - 200));
	else if(used_e > 400 && used_e <= 1000)
		money_for_e = floor(7300 + 200 * 93.3 + 200 * 187.9 + 280.6 * (used_e - 400));
	else
		if(month == 7 || month == 8 || month == 12 || month == 1 || month == 2)
			money_for_e = floor(7300 + 200 * 93.3 + 200 * 187.9 + 280.6 * 600 + 709.5 * (used_e - 1000));
		else
			money_for_e = floor(7300 + 200 * 93.3 + 200 * 187.9 + 280.6 * (used_e - 400));
	
	ext = floor(money_for_e * 0.037);
	res = money_for_e + round(money_for_e * 0.1) + ext;
	res = res - (res % 10);
	return res;
}