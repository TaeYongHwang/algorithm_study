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
		//1. ���� ���� ������
		pair <int, int> nextPos = move(curDir, curPos.first, curPos.second);
		count++;

		//2. �ش� ��ġ�� ������ ������ ������� Ȯ��
		//-1. �������� �Ѿ����
		if (nextPos.first < 0 || nextPos.first >= N)
			return count;
		else if (nextPos.second < 0 || nextPos.second >= N)
			return count;
		//-2. �ڽ��� ���� ��Ҵ��� -����� �Ծ �پ������� Ȯ���ؾߵ�
		if (find(pos.begin(), pos.end(), nextPos) != pos.end())
			return count;


		//-1 �ش� ��ġ�� ��� ���� ��� �����̸� �ٿ�����
		if (!apple[nextPos.first][nextPos.second])
			pos.erase(pos.begin());
		else //����ִ� ��� ����� ����
			apple[nextPos.first][nextPos.second] = false;
		//-2 ������ �ٲ���ϴ� ��� 
		if (!dir.empty() && dir.front().first == count) {
			curDir = changeDirection(curDir, dir.front().second);
			dir.pop();
		}


		//������Ʈ
		pos.push_back(nextPos);
		curPos = nextPos;



	}


}





//����� : [0,0]����, ���� ������


int main() {

	cin >> N >> K;

	apple = vector<vector<bool>>(N, vector<bool>(N, false));


	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		apple[row - 1][col - 1] = true; //0���ͽ����ϰ�
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