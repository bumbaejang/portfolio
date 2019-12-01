#include <stdio.h>
#include <math.h>

typedef struct point{
	int x;
	int y;
} Point;

typedef struct rectangle{
	Point lowerLeft;
	Point higherRight;
} Rectangle;

int main() {
	Rectangle R;
	
	scanf("%d %d %d %d", &R.lowerLeft.x, &R.lowerLeft.y, &R.higherRight.x, &R.higherRight.y);
	
	int area;
	area = abs(R.lowerLeft.x - R.higherRight.x) * abs(R.lowerLeft.y - R.higherRight.y);
	printf("%d", area);
	return 0;
}
