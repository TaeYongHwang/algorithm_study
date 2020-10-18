#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> cache[100][100]; //cache[i][j].first : 해당 부분에서의 최대합
								 //cache[i][j].first : 최대합의 갯수.
int tri[100][100];


pair<int, int> find_max(int row, int col, int N) {
	
	pair<int, int> & ret = cache[row][col];

	//basecase 1 : 이미 차있는 경우
	if (ret.first != -1)
		return ret;

	//basecase 2 : 마지막 열에 도달한 경우
	if (row == N - 1) {
		ret.first = tri[row][col];
		ret.second = 1;
		return ret;
	}

	pair<int, int > down = find_max(row + 1, col, N);
	pair<int, int> down_right = find_max(row + 1, col + 1, N);

	//아래와 아래오른쪽 값 비교
	if (down.first > down_right.first) {
		ret.first = tri[row][col] + down.first;
		ret.second = down.second;
	}
	else if (down.first == down_right.first) {
		ret.first = tri[row][col] + down.first;
		ret.second = down.second + down_right.second;
		
	}
	else {
		ret.first = tri[row][col] + down_right.first;
		ret.second = down_right.second;
	}

	return ret;



}









int main()
{
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
				cache[i][j].first = -1;
				cache[i][j].second = -1;
			}
		}

		cout << find_max(0, 0, n).second << endl;






	}



	return 0;
}


