#include <stdio.h>
int main() {
	char text[1000];
	int ch;
	int index = 0;
	
	while((ch = getchar()) != EOF){
		text[index] = ch;
		index++;
	}
	text[index] = '\0';
	
	int i = 0;
	int num_count = 0;
	int upper_count = 0;
	int lower_count = 0;

	
	while(i < index){
		if(isdigit(text[i])){
			num_count++;
			i++;
		}else if(isupper(text[i])){
			upper_count++;
			i++;
		}else if(islower(text[i])){
			lower_count++;
			i++;
		}else
			i++;
	}
	
	printf("%d %d %d", num_count, lower_count, upper_count);
	return 0;
}
