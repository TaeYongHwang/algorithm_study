#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		if (str.size() != 7) {
			cout << 0 << endl;
		}
		else
		{
			if (str[0] == str[1] && str[1] == str[4] && str[0] != str[2])
				if (str[2] == str[3] && str[3] == str[5] && str[5] == str[6]) {
					cout << 1 << endl;
					continue;
				}
			cout << 0 << endl;

		}


	}




	return 0;
}