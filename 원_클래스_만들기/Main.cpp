#include <iostream>
#include <cstring>

using namespace std;
class circle{
	private:
	int radius;
	string color;
	public:
	circle();
	circle(int r) : radius(r){}
	double calcArea(){
		return radius * radius * 3.14;
	}
};
int main() {
	int r;
	cin >> r;
	circle c(r);
	cout << c.calcArea() << endl;
	return 0;
}