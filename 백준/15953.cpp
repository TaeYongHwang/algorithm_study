#include <iostream>
using namespace std;

int main() {
	int arr1[101] = { 0, };
	int prize1[6] = { 500, 300, 200, 50, 30, 10 };

	int idx = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= i; j++) {
			arr1[idx++] = prize1[i];
		}
	}


	int arr2[65] = { 0, };
	int prize2[5] = { 512,256,128,64,32 };
	int count = 1;
	idx = 1;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < count; j++) {
			arr2[idx++] = prize2[i];
		}
		count *= 2;
	}

	

	int a, b,T;
	cin >> T;
	while (T--) {
		cin >> a >> b;

		cout << (arr1[a] + arr2[b]) * 10000<<endl;

	}


	

	return 0;
}