#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
using namespace std;

int N, M;
vector<vector<int>> board;



int ans = 10000;
int cctvIdx = 10;

void oneDirCCTV(const int caseNum, int row, int col, int fill) {

	switch (caseNum) {
	case 0:	 // 위
		for (int i = row - 1; i >= 0; i--) {
			if (board[i][col] == 6)
				break;
			if (board[i][col] >= 1 && board[i][col] <= 5)
				continue;

			board[i][col] += fill;
		}
		break;
	case 1: //오른쪽
		for (int i = col + 1; i < M; i++) {
			if (board[row][i] == 6)
				break;
			if (board[row][i] >= 1 && board[row][i] <= 5)
				continue;
			board[row][i] += fill;
		}
		break;

	case 2: //아래
		for (int i = row + 1; i < N; i++) {
			if (board[i][col] == 6)
				break;
			if (board[i][col] >= 1 && board[i][col] <= 5)
				continue;
			board[i][col] += fill;
		}
		break;

	case 3:  //왼쪽
		for (int i = col - 1; i >= 0; i--) {
			if (board[row][i] == 6)
				break;
			if (board[row][i] >= 1 && board[row][i] <= 5)
				continue;
			board[row][i] += fill;
		}
		break;

	
	}
}


void findAns(int row, int col) {
	//basecase 
	if (row == N - 1 && col == M) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0)
					count++;
			}
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		*/
		ans = min(ans, count);
		return;
	}
	//사각형 범위에 맞게 조절해주는 장치
	if (col == M) {
		findAns(row + 1, 0);
		return;
	}



	//else
	switch (board[row][col]) {
	case 1: {
		int idx = cctvIdx++;
		for (int i = 0; i < 4; i++) {
			oneDirCCTV(i, row, col, idx);
			findAns(row, col + 1);
			oneDirCCTV(i, row, col, -idx);

		}
		break;
	}
	case 2: {
		int idx = cctvIdx++;
		int dir1[2] = { 0,1 };
		int dir2[2] = { 2,3 };
		for (int i = 0; i < 2; i++) {
			oneDirCCTV(dir1[i], row, col, idx);
			oneDirCCTV(dir2[i], row, col, idx);
			findAns(row, col + 1);
			oneDirCCTV(dir1[i], row, col, -idx);
			oneDirCCTV(dir2[i], row, col, -idx);
		}

		break;
	}
	case 3: {
		int idx = cctvIdx++;
		int dir1[4] = { 0,1,2,3 };
		int dir2[4] = { 1,2,3,0 };

		for (int i = 0; i < 4; i++) {
			oneDirCCTV(dir1[i], row, col, idx);
			oneDirCCTV(dir2[i], row, col, idx);
			findAns(row, col + 1);
			oneDirCCTV(dir1[i], row, col, -idx);
			oneDirCCTV(dir2[i], row, col, -idx);
		}
		break;
	}
	case 4: {
		int idx = cctvIdx++;
		int dir1[4] = { 0,0,1,0 };
		int dir2[4] = { 1,1,2,2 };
		int dir3[4] = { 3,2,3,3 };
		for (int i = 0; i < 4; i++) {
			oneDirCCTV(dir1[i], row, col, idx);
			oneDirCCTV(dir2[i], row, col, idx);
			oneDirCCTV(dir3[i], row, col, idx);
			findAns(row, col + 1);
			oneDirCCTV(dir1[i], row, col, -idx);
			oneDirCCTV(dir2[i], row, col, -idx);
			oneDirCCTV(dir3[i], row, col, -idx);
		}
		break;
	}
	case 5: {
		int idx = cctvIdx++;
		for (int i = 0; i < 4; i++) {
			oneDirCCTV(i, row, col, idx);
		}
		findAns(row, col + 1);
		for (int i = 0; i < 4; i++) {
			oneDirCCTV(i, row, col, -idx);
		}
		break;
	}
	default:
		findAns(row, col + 1);
		break;

	}

}

int main() {
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			board[i].push_back(temp);
		}
	}


	findAns(0, 0);
	cout << ans << endl;
	return 0;


}