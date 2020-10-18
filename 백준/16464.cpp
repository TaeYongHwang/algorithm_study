#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//분할 정복
//부분합이 왼쪽, 걸쳐있음 오른쪽
bool is_ans(const int k){
	//홀수인 경우 무조건 만들 수 있다.
	if (k % 2 == 1)
		return true;

	//짝수인 경우
	int value = k-1, count = 1;
	while (value > 0) {
		count++;
		value -= count;
		if (value % count == 0) {
			return true;
		}
	}

	return false;
}





int main()
{
	int C;
	cin >> C;
	while (C--) {
		int K;
		cin >> K;
		if (is_ans(K))
			cout << "Gazua" << endl;
		else
			cout << "GoHanGang" << endl;

	}


	return 0;
}
