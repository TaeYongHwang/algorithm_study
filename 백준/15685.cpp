#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector < pair<int,int>> startPos;
vector <int> startDir;
vector <int> curG;
vector<vector<bool>> board = vector<vector<bool>> (101, vector<bool>(101,false));

enum {
	RIGHT, UP, LEFT, DOWN
};

int changeDir(int curDir) {
	
	if (curDir == DOWN) {
		return RIGHT;
	}

	return curDir + 1;
}


vector<int> makeGenerations(int curDir, int curGeneration) {

	vector<vector<int>> generations = vector<vector<int>>(curGeneration+1, vector<int>());

	generations[0].push_back(curDir);

	for (int i = 1; i < generations.size(); i++) {
		//이전 세대 그대로 가져옴
		generations[i] = generations[i - 1];
		for (int j = generations[i-1].size()-1; j>=0; j--) {
			//이전 세대를 거꾸로 방향을 전환해서 추가
			generations[i].push_back(changeDir(generations[i-1][j]));
		}

	}

	return generations[curGeneration];
}


void draw_one(int row, int col, const vector<int>& curve, int count =0) {

	board[row][col] = true;


	//basecase
	if (count == curve.size())
		return;

	
	switch (curve[count]) {
		case LEFT:
			draw_one(row, col - 1, curve, count + 1);
			break;

		case RIGHT:
			draw_one(row, col + 1, curve, count + 1);
			break;

		case UP:
			draw_one(row - 1, col, curve, count + 1);
			break;

		case DOWN:
			draw_one(row + 1, col, curve, count + 1);
			break;
	}

}



int findAns() {
	int size = startPos.size();
	int ans = 0;
	for (int i = 0; i < size; i++) {
		int row = startPos[i].first;
		int col = startPos[i].second;
		vector<int> curCurve = makeGenerations(startDir[i], curG[i]);
		
		draw_one(row, col, curCurve);
	}




	for (int i = 0; i < board.size() - 1; i++) {
		for (int j = 0; j < board[i].size() - 1; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				ans++;

		}

	}


	return ans;

}










int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int row, col, d, g;
		cin >> col >> row >> d >> g;
		startPos.push_back({ row, col });
		startDir.push_back(d);
		curG.push_back(g);
	}

	cout << findAns()<<endl;
	
	/*
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	*/
	return 0;
}