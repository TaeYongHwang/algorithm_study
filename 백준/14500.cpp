#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visit;



//������ ����쿡 ã�� �� ����
int findAns(int row, int col, int count = 1) {
	int maxV = -1;
	//basecase
	if (count == 4) {
		return board[row][col];
	}

	//4�������� Ȯ��

	//1. ����
	if (col - 1 >= 0 && !visit[row][col-1]) {
		visit[row][col - 1] = true;
		maxV = max(maxV,board[row][col] + findAns(row, col - 1, count + 1));
		visit[row][col - 1] = false;
	}

	//2. ������
	if (col + 1 < M && !visit[row][col +1]) {
		visit[row][col + 1] = true;
		maxV = max(maxV, board[row][col] + findAns(row, col + 1, count + 1));
		visit[row][col + 1] = false;
	}

	//3. ����
	if (row - 1 >= 0 && !visit[row-1][col]) {
		visit[row - 1][col] = true;
		maxV = max(maxV, board[row][col] + findAns(row - 1, col, count + 1));
		visit[row - 1][col] = false;
	}

	//4.�Ʒ�
	if (row + 1 < N && !visit[row+1][col]) {
		visit[row + 1][col] = true;
		maxV = max(maxV, board[row][col] + findAns(row + 1, col, count + 1));
		visit[row + 1][col] = false;
	}

	return maxV;
}

//�� �� �� �� �� ��쿡�� ���� ã������ϴµ�
int findAns2(int row, int col) {
	vector <int> v;
	
	//1. ����
	if (col - 1 >= 0 ) {
		v.push_back(board[row][col - 1]);
	
	}

	//2. ������
	if (col + 1 < M ) {
		v.push_back(board[row][col + 1]);
	}

	//3. ����
	if (row - 1 >= 0 ) {
		v.push_back(board[row - 1][col]);

	}

	//4.�Ʒ�
	if (row + 1 < N ) {
		v.push_back(board[row + 1][col]);

	}

	if (v.size() < 3)
		return -1;
	else {
		sort(v.begin(), v.end());
		int x = v.size();
		return v[x - 1] + v[x - 2] + v[x - 3] + board[row][col];
	}


}



int main() {
	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>());
	visit = vector<vector<bool>>(N, vector<bool>(M, false));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			board[i].push_back(temp);
		}

	}

	int maxV = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			//cout << "findAns " << i << ' ' << j << ' ' << ':' << findAns(i, j) << endl;
			maxV = max(maxV, findAns(i, j));
			maxV = max(maxV, findAns2(i, j));
			visit[i][j] = false;
		}
	}

	cout << maxV << endl;

	return 0;


}