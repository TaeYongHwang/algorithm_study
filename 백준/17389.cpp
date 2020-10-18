#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string ox;

int main()
{
	cin >> N;
	cin >> ox;

	int sum = 0;
	int bonus = 0;
	for (int i = 0; i < N; i++) {
		if (ox[i] == 'O') {
			sum += i + 1;
			sum += bonus++;
			continue;
		}
		bonus = 0;
	}

	cout << sum << endl;



	return 0;
}