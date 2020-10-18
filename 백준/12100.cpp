#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<vector<int>> trim(int op, const vector<vector<int>>& board) {
	vector<vector<int>> temp = vector<vector<int>>(N, vector<int>());

	if (op == 1 or op == 2) { //좌우로
		
		//1. 0을 없앤 벡터를 먼저 만듦 (각 행에 대해)
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != 0)
					temp[i].push_back(board[i][j]);
			}
		}
		if (op == 1) { //왼쪽으로
			for (int i = 0; i < board.size(); i++) {
				while (temp[i].size() < N) {
					temp[i].push_back(0);
				}
			}
		}
		else {  //오른쪽으로
			for (int i = 0; i < board.size(); i++) {
				reverse(temp[i].begin(), temp[i].end());
				while (temp[i].size() < N) {
					temp[i].push_back(0);
				}
				reverse(temp[i].begin(), temp[i].end());
			}
		}
	}

	else{ //위아래
		temp = vector<vector<int>>(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			vector<int> colVector;
			for (int j = 0; j < N; j++) {
				if (board[j][i] != 0)
					colVector.push_back(board[j][i]);
			}
			if (op == 3) { //위
				while (colVector.size() < N)
					colVector.push_back(0);
			}
			else { //아래
				reverse(colVector.begin(), colVector.end());
				while (colVector.size() < N)
					colVector.push_back(0);
				reverse(colVector.begin(), colVector.end());
			}

			for (int j = 0; j < colVector.size(); j++) {
				temp[j][i] = colVector[j];
			}

		}


	}
	/*
	cout << "trim " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << temp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	*/

	return temp;
}

vector<vector<int>> calculation(int op, vector<vector<int>> board) {
	switch (op) {
		case 1://왼쪽
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N-1; j++) {
					if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
						board[i][j] *= 2;
						board[i][j + 1] = 0;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j > 0; j--) {
					if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
						board[i][j] *= 2;
						board[i][j - 1] = 0;
					}
				}
			}

			break;

		case 3: //위
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N - 1; j++) {
					if (board[j][i] != 0 && board[j][i] == board[j + 1][i]) {
						board[j][i] *= 2;
						board[j + 1][i] = 0;
					}
				}
			}
			break;

		case 4:
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j > 0; j--) {
					if (board[j][i] != 0 && board[j][i] == board[j - 1][i]) {
						board[j][i] *= 2;
						board[j - 1][i] = 0;
					}
	
				}
			}
			break;

	}
	/*
	cout << "board " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	*/

	return board;

}

int findMax(vector<vector<int>>& board) {
	int maxV = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxV = max(maxV, board[i][j]);
		}
	}

	return maxV;
}


int dfs(vector<vector<int>> board, int limit = 0) {
	int maxV = -1;
	
	if (limit == 5) {
/*
		cout << "board " << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		*/
		return findMax(board);
	}

	for (int i = 1; i <= 4; i++) {
		maxV = max(maxV,dfs(trim(i, calculation(i, trim(i, board))), limit+1));
	}

	return maxV;


}




int main() {
	cin >> N;
	vector<vector<int>> board = vector<vector<int>>(N, vector<int>(0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			board[i].push_back(temp);
		}
	}



	cout << dfs(board)<<endl;




}