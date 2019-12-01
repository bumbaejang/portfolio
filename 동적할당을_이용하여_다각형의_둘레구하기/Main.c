#include <stdio.h>
#include <math.h>

struct Point{
	int x;
	int y;
};

double perimeter(struct Point polygon[], int n){
	int i;
	int xd, yd;
	double result = 0.0;
	
	for(i=0;i<n-1;i++){
		xd = polygon[i].x - polygon[i+1].x;
		yd = polygon[i].y - polygon[i+1].y;
		result += sqrt((xd * xd) + (yd * yd));
	}
	xd = polygon[n-1].x - polygon[0].x;
	yd = polygon[n-1].y - polygon[0].y;
	result += sqrt((xd * xd) + (yd * yd));
	
	return result;
}

int main() {
	int n, i;
	scanf("%d", &n);
	struct Point *polygon = (struct Point*) malloc(sizeof(struct Point)*n);
		
	for(i=0;i<n;i++){
		scanf("%d %d", &polygon[i].x, &polygon[i].y);
	}
	
	printf("%.2f", perimeter(polygon, n));
	free(polygon);
	
	return 0;
}
