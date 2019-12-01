#include <stdio.h>
int main() {
	float A_Left, A_Right;
	float B_Left, B_Right;
	float N_A_Left, N_A_Right;
	float N_B_Left, N_B_Right;
	float Overlap_Left, Overlap_Right;
	
	scanf("%f %f", &A_Left, &A_Right);
	scanf("%f %f", &B_Left, &B_Right);
	
	if(A_Left > B_Left){
		N_A_Left = B_Left;
		N_A_Right = B_Right;
		N_B_Left = A_Left;
		N_B_Right = A_Right;
	}
	else{
		N_A_Left = A_Left;
		N_A_Right = A_Right;
		N_B_Left = B_Left;
		N_B_Right = B_Right;
	}	
	
	if(N_B_Left <= N_A_Right){
		Overlap_Left = N_B_Left;
		if(N_B_Right <= N_A_Right)
			Overlap_Right = N_B_Right;
		else
			Overlap_Right = N_A_Right;
	}
	else{
		Overlap_Right = -9999;
		Overlap_Left = -9999;
	}
	
	printf("%.2f", Overlap_Right - Overlap_Left);
	return 0;
}
