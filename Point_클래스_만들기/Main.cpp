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

int main() {
	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	point p1(x, y);
	point p2(x1, y1);
	cout << p1.distance(p2) << endl;
	p1.move(x1, y1);
	cout << p1.getx() << "\t" << p1.gety() << endl;
	return 0;
}