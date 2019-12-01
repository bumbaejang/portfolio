#include <stdio.h>
int main() {
	char str[100];
	int i;
	int count = 0;
	
	gets(str);

	for(i=0;i<100;i++){
		if(str[i] != '\0')
			count++;
		else
			break;
	}
	
	printf("%d", count);
	
	return 0;
}
