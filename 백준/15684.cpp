#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
vector<vector<int>> lines;
	//lines[i] �� ���� �󿡼��� ������.

bool isPossible() {
	for (int i = 0; i < N; i++) { //��� �����ٿ�����
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

//���� ���ο��� ���ڷ� ���� �Ѱ��༭
//��� ������ ����ġ�⸸ ����
int findAns(int row = 0, int count = 0) {
	//�̸� ����غ���
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
		//�ε����� 0���� �ϰԲ�.
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