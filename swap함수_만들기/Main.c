#include <stdio.h>
void swap(int *px, int *py);
int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b)
		swap(&a, &b);
	if(b > c)
		swap(&b, &c);
	if(a > b)
		swap(&a, &b);
	
	printf("%d %d %d", a, b ,c);
	
	return 0;
}
 
void swap(int *px, int *py){
	int tmp;
	
	tmp = *px;
	*px = *py;
	*py = tmp;
} 