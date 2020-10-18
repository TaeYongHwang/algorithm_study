#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;

enum Direction {
	NORTH, EAST, SOUTH, WEST
};


int changeDir(int dir) {

	if (dir == NORTH)
		return WEST;

	return dir - 1;

}


int findAns(int row, int col, int dir) {
	int count = 0;
	//1. 현재 위치 청소
	if (board[row][col] == 0) {
		count++;
		board[row][col] = 2;
	}

	//4방향 모두 비지 않은 경우
	if (board[row + 1][col] != 0 && board[row - 1][col] != 0 && board[row][col + 1] != 0 && board[row][col - 1] != 0) {
		int backRow, backCol;
		if (dir == NORTH) {
			backRow = row + 1;
			backCol = col;
		}
		else if (dir == SOUTH) {
			backRow = row - 1;
			backCol = col;
		}
		else if (dir == EAST) {
			backRow = row;
			backCol = col - 1;
		}
		else if(dir == WEST){
			backRow = row;
			backCol = col + 1;
		}

		//뒤가 벽인 경우
		if (board[backRow][backCol] == 1)
			return count;
		else
			return count + findAns(backRow, backCol, dir);
	}

	//한방향이라도 청소할 곳이 존재
	for (int i = 0; i < 4; i++) {
		dir = changeDir(dir);
		if (dir == NORTH) {
			if(board[row -1][col] == 0)
				return count + findAns(row - 1, col, dir);

		}
		else if (dir == SOUTH) {
			if(board[row + 1][col] == 0)
				return count + findAns(row + 1, col, dir);


		}
		else if (dir == EAST) {
			if(board[row ][col +1] == 0)
				return count + findAns(row , col+1, dir);

		}
		else if (dir == WEST) {
			if(board[row][col -1] == 0)
				return count + findAns(row, col - 1, dir);

		}


	}




}


int main() {
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>());

	int r, c, d;
	cin >> r >> c >> d;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			board[i].push_back(temp);
		}
	}

	cout << findAns(r, c, d) << endl;

	return 0;


}