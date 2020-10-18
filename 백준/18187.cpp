#include <iostream>

using namespace std;

int main() {
	int arr[3];
	int n;
	cin >> n;
	int m = n / 3;
	int k = n % 3;

	for (int i = 0; i < 3; i++) {
		arr[i] = m;
		if (k != 0) {
			arr[i] ++;
			k--;
		}
	}

	cout << (n + 1) + (arr[0] * arr[1] + arr[0] * arr[2] + arr[1] * arr[2]);

	

	return 0;
}