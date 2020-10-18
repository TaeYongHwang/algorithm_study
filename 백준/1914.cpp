#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

void hanoi(int N, int from, int tmp, int to) {
	if (N == 1) {
		cout << from << ' ' << to << '\n';
	}

	else {
		hanoi(N - 1, from, to, tmp);
		cout << from << ' ' << to << '\n';
		hanoi(N - 1, tmp, from, to);

	}


}

string bigSubtract(string cur) {
	cur[cur.size() - 1] -= 1;
	return cur;

}

string bigNumber(int n , string cur = "2" ,int count = 1) {
	if (count == n) {
		reverse(cur.begin(), cur.end());
		return bigSubtract(cur);
	}
	string tmp ="";
	int carry = 0;
	for (int i = 0; i < cur.size(); i++) {
		int digit = cur[i] - '0';
		int val = carry + digit * 2;

		if (val >= 10) {
			carry = 1;
			tmp.push_back((val % 10) + '0');
		}
		else {
			carry = 0;
			tmp.push_back((val % 10) + '0');
		}
	}

	if (carry == 1) {
		tmp.push_back('1');
	}
	
	return bigNumber(n, tmp, count + 1);

}







int main() {
	int N;
	cin >> N;
	
	cout << bigNumber(N)<<endl;
	if (N <= 20) {
		hanoi(N, 1, 2, 3);
	}
	

	
	
	return 0;
}

