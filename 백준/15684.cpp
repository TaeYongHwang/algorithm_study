#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
vector<vector<int>> lines;
	//lines[i] 가 문제 상에서의 세로줄.

bool isPossible() {
	for (int i = 0; i < N; i++) { //모든 세로줄에대해
		int cur = i;
		for (int j = 0; j < H; j++) {
			if (lines[cur][j] != -1) {
				cur = lines[cur][j];
			}
		}

		if (i != cur)
			return false;
	}

	return true;

}

//시작 세로열을 인자로 같이 넘겨줘서
//어느 정도의 가지치기만 했음
int findAns(int row = 0, int count = 0) {
	//미리 계산해보기
	bool cur_result = isPossible();
	int ans = 100;

	if (cur_result)
		return count;
	else if (count == 3)
		return ans;

	
	for (int i = row; i < N-1; i++) {
		for (int j = 0; j < H; j++) {

			if (lines[i][j] == -1 && lines[i + 1][j] == -1) {
				lines[i][j] = i + 1;
				lines[i + 1][j] = i;
				ans = min(ans, findAns(i,count + 1));

				lines[i][j] = -1;
				lines[i + 1][j] = -1;

			}
		}
	}
	
	return ans;
}





int main() {
	cin >> N >> M >> H;
	lines = vector<vector<int>>(N, vector<int>(H, -1));


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//인덱싱을 0부터 하게끔.
		a--;
		b--;

		lines[b][a] = b+1;
		lines[b+1][a] = b;

	}

	int ans = findAns();
	if (ans == 100)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}