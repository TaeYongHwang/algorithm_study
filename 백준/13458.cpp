#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, B, C;
	long long count = 0;
	vector<int> room;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		room.push_back(tmp);
	}
	cin >> B >> C;

	for (int i = 0; i < room.size(); i++) {
		count++;
		room[i] -= B;
		if (room[i] <= 0)
			continue;
		
		count += room[i] / C;
		if (room[i] % C != 0)
			count++;
	}

	cout << count << endl;

}