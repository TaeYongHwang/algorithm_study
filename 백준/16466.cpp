#include <iostream>
#include <vector>
using namespace std;



int main() {
	int N;
	cin >> N;
	bool tickets[1000001] = { false };
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		tickets[temp] = true;
	}
	int idx = 1;
	while (idx<= N) {
		if (tickets[idx] == false)
			break;

		idx++;
	}

	cout << idx << endl;




}