#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
using namespace std;


map<vector<string>, int> m;
int row,col;

pair<int, int> findPos(char color, const vector <string> v) {

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == color)
				return { i,j };
		}
	}
}

void swapPos(pair<int,int> src, int op, vector<string>& v) { //갈 수 있는 최대만큼 가서 스왑
	
	char c = v[src.first][src.second];
	
	int row = src.first;
	int col = src.second;



	switch (op) {
		case 1: //왼
			while (v[row][col - 1] == '.') {
				col--;
			}
			break;

		case 2: //오른
			while (v[row][col + 1] == '.') {
				col++;
			}
			break;

		case 3: //아래
			while (v[row+1][col] == '.') {
				row++;
			}
			break;

		case 4: //위
			while (v[row - 1][col] == '.') {
				row--;
			}
			break;

	}

	v[src.first][src.second] = v[row][col];
	v[row][col] = c;

}



//해당 op를 통해 구멍에 들어갈 수 있는 경우 true;
//나머지 false 후, v에 대한 값변경이 있음
bool goal(int op, char color, const vector<string>& v) {
	pair<int, int> ball = findPos(color, v);
	int  row = ball.first;
	int  col = ball.second;

	//왼, 오, 위, 아래.
	switch (op) {
	case 1: //왼쪽
		while (v[row][col - 1] == '.') {
			col--;
		}
		if (v[row][col-1] == 'O')
			return true;
		break;

	case 2: //오른쪽
		while (v[row][col + 1] == '.') {
			col++;
		}
		if (v[row][col+1] == 'O')
			return true;
		break;

	case 3: //아래
		while (v[row + 1][col] == '.') {
			row++;
		}
		if (v[row+1][col] == 'O')
			return true;
		break;

	case 4: //위
		while (v[row - 1][col] == '.') {
			row--;
		}
		if (v[row-1][col] == 'O')
			return true;
		break;
	}
	return false;


}

//두 색깔이 operation에 대해 어느 쪽에 존재하는지 확인 후 이동시켜야함 (해당 방향쪽에 치우친 걸 먼저하게)

vector<string> nextState(int op, vector<string> v) {
	pair<int, int> red = findPos('R',v);
	pair<int, int> blue = findPos('B',v);

	switch (op) {
		case 1:
			if (red.second < blue.second) {
				swapPos(red, op,v);
				swapPos(blue, op, v);
			}
			else {
				swapPos(blue, op, v);
				swapPos(red, op, v);
			}
			break;

		case 2:
			if (red.second > blue.second) {
				swapPos(red, op, v);
				swapPos(blue, op, v);
			}
			else {
			swapPos(blue, op, v);
			swapPos(red, op, v);
			}
			break;
		
		case 3: //아래
			if (red.first > blue.first) {
				swapPos(red, op, v);
				swapPos(blue, op, v);
			}
			else {
				swapPos(blue, op, v);
				swapPos(red, op, v);
			}


			break;
		case 4: //위
			if (red.first < blue.first) {
				swapPos(red, op, v);
				swapPos(blue, op, v);
			}
			else {
				swapPos(blue, op, v);
				swapPos(red, op, v);
			}
			break;


	}

	return v;


}






int dfs(vector <string> v) {

	queue<vector<string>> q;
	m[v] = 0;
	q.push(v);

	while (!q.empty()) {
		vector<string> cur = q.front();
		int count = m[cur];
		q.pop();
		/*
		for (int i = 0; i < cur.size(); i++) {
			for (int j = 0; j < cur[i].size(); j++) {
				cout << cur[i][j] << ' ';
			}
			cout << endl;
		}*/




		if (count > 9)
			return -1;


		for (int i = 1; i <= 4; i++) {
			//정답인경우
			//빨간색 넣은 후에, 파란색 안들어가는경우
			if (goal(i, 'R', cur)) {
				vector<string> tmp = cur;
				pair<int, int> pos = findPos('R', tmp);
				tmp[pos.first][pos.second] = '.';
				if (!goal(i, 'B', tmp)) {
					return count + 1;
				}
			}

			//정답 x 중에, queue에 추가해줘야 하는 경우
			if (!goal(i, 'R',cur) && !goal(i, 'B',cur)) {
				vector<string> next = nextState(i, cur);
				if (m.find(next) == m.end()) {
					q.push(next);
					m[next] = count + 1;
				}
			}


		}
	}

	return -1;
}



int main() {

	vector <string> v;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	cout << dfs(v) << endl;
	
	



	return 0;
}