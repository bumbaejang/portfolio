#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string s_find, s_change;
	
	getline(cin, str);
	cin >> s_find >> s_change;
	
	int position = str.find(s_find);
	str.replace(position, s_find.length(), s_change);
	
	cout<< str << endl;
	return 0;
}