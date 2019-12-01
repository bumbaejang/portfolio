#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str){
	int size = strlen(str);
	char tmp;
	int i;
	
	for(i=0;i<size/2;i++){
		tmp = str[i];
		str[i] = str[size-i-1];
		str[size-i-1] = tmp;
	}
}

int main() {
	char str[100];
	
	scanf("%s", str);
	reverse(str);
	printf("%s", str);
	
	return 0;
}
