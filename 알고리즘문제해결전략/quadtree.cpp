#include <iostream>
#include <vector>
#include <string>

using namespace std;

string origin;


string upside_down(string cur_string)
{
	if (cur_string.front() == 'x') {
		int idx = 1;
		string LeftUp = upside_down(cur_string.substr(idx));
		
		//이전 스트링 값을 알면 그 길이도 알 수 있다.
		idx += LeftUp.size();
		string RightUp = upside_down(cur_string.substr(idx));

		idx += RightUp.size();
		string LeftDown = upside_down(cur_string.substr(idx));

		idx += LeftDown.size();

		string RightDown = upside_down(cur_string.substr(idx));
		

		string upside_downed_str = 'x' + LeftDown + RightDown + LeftUp + RightUp;

		return upside_downed_str;

	}
	
	string str = "";
	str += cur_string.front();
	return str;
}



int main()
{
	int C;
	cin >> C;

	while (C--) {
	
		cin >> origin;

		cout << upside_down(origin) << endl;

	}

	return 0;
}