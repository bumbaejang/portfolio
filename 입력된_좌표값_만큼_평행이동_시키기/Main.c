#include <stdio.h>
#include <math.h>

typedef struct point{
	int x;
	int y;
} point;

void move(struct point* p, int deltaX, int deltaY){
	(*p).x = (*p).x + deltaX;
	(*p).y = (*p).y + deltaY;
}
int main() {
	point p1, p2;
	int dx, dy;
	
	scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
	scanf("%d %d", &dx, &dy);
	move(&p1, dx, dy);
	move(&p2, dx, dy);
	
	printf("%d %d %d %d", p1.x, p1.y, p2.x, p2.y);
	return 0;
}
