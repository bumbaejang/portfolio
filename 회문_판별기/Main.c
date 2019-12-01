#include <stdio.h>
#include <string.h>

int palindrome(char str[]){
	int len = strlen(str);
	int i;
	for(i=0;i<len;i++){
		if(str[i] != str[len-i-1])
			return 0;
	}
	return 1;
}

int main() {
	char str[100];
	scanf("%s", str);
	printf("%d", palindrome(str));

	return 0;
}
