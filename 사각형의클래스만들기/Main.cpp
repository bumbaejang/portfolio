#include <iostream>
#include <cmath>
using namespace std;

class point{
private:
	int x;
	int y;
public:
	point(){};
	point(int x1, int y1);
	void move(int x1, int y1);
	int distance(point p);
	int getx();
	int gety();
	void setxy(int vx, int vy){
		x = vx;
		y = vy;
	}
};
point::point(int x2, int y2):x(x2), y(y2){}
void point::move(int x1, int y1){
	x += x1;
	y += y1;
}

int point::distance(point p){
	int disx;
	int disy;
	int dis;
	disx = x - p.x;
	disy = y - p.y;
	dis = sqrt((disx * disx) + (disy * disy));
	return dis;
}

int point::getx(){
	return x;
}

int point::gety(){
	return y;
}

class rectangle{
private:
	point lowerleft, upperright;
public:
	rectangle(){};
	rectangle(int llx, int lly, int urx, int ury);
	point getllp();
	point geturp();
	int area();
	int perimeter();
	void move(point p);
};
rectangle::rectangle(int x1, int y1, int x2, int y2):lowerleft(x1,y1), upperright(x2,y2){}

point rectangle::getllp(){
	return lowerleft;
}

point rectangle::geturp(){
	return upperright;
}

int rectangle::area(){
	int xdiff;
	int ydiff;
	int rarea;
	xdiff = upperright.getx() - lowerleft.getx();
	ydiff = upperright.gety() - lowerleft.gety();
	rarea = xdiff * ydiff;
	return rarea;
}

int rectangle::perimeter(){
	int xdiff;
	int ydiff;
	int rperi;
	xdiff = upperright.getx() - lowerleft.getx();
	ydiff = upperright.gety() - lowerleft.gety();
	rperi = (xdiff + ydiff) * 2;
	return rperi;
}

void rectangle::move(point p){
}

int main() {
	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	rectangle r(x, y, x1, y1);
	cout << r.area() << endl << r.perimeter() << endl;
	return 0;
}