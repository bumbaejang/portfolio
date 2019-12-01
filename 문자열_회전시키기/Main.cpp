#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s, '\n'); // 문자열 입력
	int len = s.length(); // 문자열의 길이

	for(int i=0; i<len; i++){
		string f = s.substr(0, 1);
		string l = s.substr(1, len-1);
		s = l + f;
		cout << s << endl;
	}
}