#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;


int bfs(queue <pair<int,int>> q, vector<vector<int>> board) {

	while (!q.empty()) {
		pair<int, int> curPos = q.front();
		int row = curPos.first;
		int col = curPos.second;
		q.pop();

		//상하좌우로 퍼뜨림
		//상
		if (row - 1 >= 0 && board[row-1][col] == 0) {
			board[row-1][col] = 2;
			q.push({ row-1, col  });
		}
		//하
		if (row + 1 < N && board[row + 1][col] == 0) {
			board[row + 1][col] = 2;
			q.push({ row + 1, col });
		}
		//좌
		if (col - 1 >= 0 && board[row][col - 1] == 0) {
			board[row][col - 1] = 2;
			q.push({ row, col - 1 });
		}
		//우
		if (col + 1 < M && board[row][col + 1] == 0) {
			board[row][col + 1] = 2;
			q.push({ row, col + 1 });
		}

	}

	//정답
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)
				count++;
		}
	}

	return count;
}



int main() {
	queue <pair<int, int>> q;

	cin >> N >> M;
	vector<vector<int>> board = vector<vector<int>>(N, vector<int>());
	int ans = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			board[i].push_back(temp);

			if (temp == 2)
				q.push({ i,j });

		}
	}


	//벽 3개 추가
	for (int i = 0; i < N*M; i++) {
		int row1 = i / M ;
		int col1 = i % M;
		if (board[row1][col1] != 0)
			continue;

		board[row1][col1] = 1;
		
		for (int j = i + 1; j < N*M; j++) {
			int row2 = j / M;
			int col2 = j % M;
			if (board[row2][col2] != 0)
				continue;
			board[row2][col2] = 1;

			for (int k = j + 1; k < N*M; k++) {
				int row3 = k / M;
				int col3 = k % M;
	

				if (board[row3][col3] != 0)
					continue;
				board[row3][col3] = 1;

				
				ans = max(ans, bfs(q, board));

				board[row3][col3] = 0;

			}
			board[row2][col2] = 0;
		}
		board[row1][col1] = 0;
	}


	cout << ans << endl;

	return 0;

}