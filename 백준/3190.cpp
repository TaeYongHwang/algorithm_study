#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int N, K, X;
vector<vector<bool>> apple;
queue <pair<int, char>> dir;



enum Direction {
	R, D, L, U,
};
Direction changeDirection(Direction d, char c) {
	if (c == 'L') {
		if (d == R)
			return U;
		else
			return Direction(d - 1);

	}
	else {
		if (d == U)
			return R;
		else
			return Direction(d + 1);


	}

}

pair<int, int> move(Direction d, int row, int col) {
	switch (d) {
	case L:
		return { row , col - 1 };
	case R:
		return { row, col + 1 };
	case U:
		return { row - 1, col };
	case D:
		return { row + 1, col };
	}
}




int findAns() {
	vector <pair< int, int> > pos;
	int count = 0;
	pair <int, int> curPos = { 0,0 };
	Direction curDir = R;
	pos.push_back(curPos);

	while (1) {
		//1. 먼저 뱀을 움직임
		pair <int, int> nextPos = move(curDir, curPos.first, curPos.second);
		count++;

		//2. 해당 위치가 게임이 끝나는 경우인지 확인
		//-1. 보드판을 넘어갔는지
		if (nextPos.first < 0 || nextPos.first >= N)
			return count;
		else if (nextPos.second < 0 || nextPos.second >= N)
			return count;
		//-2. 자신의 몸에 닿았는지 -사과를 먹어서 줄어드는지를 확인해야됨
		if (find(pos.begin(), pos.end(), nextPos) != pos.end())
			return count;


		//-1 해당 위치에 사과 없는 경우 몸길이를 줄여야함
		if (!apple[nextPos.first][nextPos.second])
			pos.erase(pos.begin());
		else //사과있는 경우 사과만 없앰
			apple[nextPos.first][nextPos.second] = false;
		//-2 방향을 바꿔야하는 경우 
		if (!dir.empty() && dir.front().first == count) {
			curDir = changeDirection(curDir, dir.front().second);
			dir.pop();
		}


		//업데이트
		pos.push_back(nextPos);
		curPos = nextPos;



	}


}





//뱀시작 : [0,0]에서, 방향 오른쪽


int main() {

	cin >> N >> K;

	apple = vector<vector<bool>>(N, vector<bool>(N, false));


	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		apple[row - 1][col - 1] = true; //0부터시작하게
	}

	cin >> X;
	for (int i = 0; i < X; i++) {
		int tmpInt;
		char tmpChar;
		cin >> tmpInt >> tmpChar;
		dir.push({ tmpInt, tmpChar });
	}

	cout << findAns() << endl;




	return 0;
}