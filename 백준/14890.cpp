#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;



bool isPossible(vector<vector<int>>& board, vector<bool>&road, int startIdx) {

	//1. 범위내인지 확인
	if (startIdx<0 || startIdx + L > N)
		return false;

	for (int i = startIdx; i < startIdx + L; i++) {
		if (road[i] == true)
			return false;
		road[i] = true;
	}
	
	return true;

}




int findNonAns(vector<vector<int>> board) {
	int sum = 0;
	for (int i = 0; i < board.size(); i++) {
		vector<bool> road = vector<bool>(N, false);

		for (int j = 0; j < board[i].size()-1; j++) {
			//1. 인접한 값이 2 이상 차이나는 경우 
			if (abs(board[i][j] - board[i][j+1]) > 1) {
				//cout << "i : " << i << endl;
				sum++;
				break;
			}
			//2. 인접한 값이 1 차이나는 경우
			//낮아진경우
			else if (board[i][j] == board[i][j + 1] + 1) {
				if (!isPossible(board, road, j + 1)) {
					//cout << "i : " << i << endl;
					sum++;
					break;
				}

			}
			//높아진경우
			else if (board[i][j] == board[i][j + 1] - 1) {
				if (!isPossible(board, road, j + 1 - L)) {
				//	cout << "i : " << i << endl;
					sum++;
					break;
				}
			}
			else
				continue;
		}


	}
	return sum;

}



int main() {
	//행에 대해서만 계산하기 위해 보드판을 2개 만듦
	vector<vector<int>> board1;
	vector<vector<int>> board2;
	cin >> N >> L;
	
	board1 = vector<vector<int>>(N, vector<int>());
	board2 = vector<vector<int>>(N, vector<int>());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			board1[i].push_back(temp);
			board2[j].push_back(temp);
		}
	}


//	cout << findNonAns(board1) << endl;
	//cout << findNonAns(board2) << endl;

	cout << 2 * N - findNonAns(board1) - findNonAns(board2) << endl;





	return 0;
}