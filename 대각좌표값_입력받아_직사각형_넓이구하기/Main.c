#include <stdio.h>
#include <math.h>
struct point{
	int x;
	int y;
};
int main(){
	struct point p1, p2;
	scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
	
	int area;
	
	area = abs(p1.x - p2.x) * abs(p1.y - p2.y);
	printf("%d", area);
	
	return 0;
}
