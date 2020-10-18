#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int N, M, K, Q;

// / : 1
// \ : 2
// ! : 3

pair<int, int> find_direction(char direction) {
	pair<int, int> p(0, 0);
	switch (direction)
	{
	case 'U':
		p.first = -1;
		break;
	case 'D':
		p.first = 1;
		break;
	case 'R':
		p.second = 1;
		break;
	case 'L':
		p.second = -1;
		break;


	}

	return p;
}


//왼쪽 유령수, 오른 쪽 거리의 합
pair<int, int> find(int row, int col, char direction, vector<vector<int>> &v, int distance = 1)
{
	//cout << "row : " << row << "col : " << col <<direction<< endl;
	pair<int, int> p(0, 0);

	//basecase : 범위 끝에 도달한 경우
	if (row == 0 || row == N + 1 || col == 0 || col == M + 1)
		return p;

	//아무것도 없는 경우
	if (v[row][col] == 0) {
		pair<int, int> dir = find_direction(direction);
		pair<int, int> val = find(row + dir.first, col + dir.second, direction, v, distance + 1);

		p.first += val.first;
		p.second += val.second;
		return p;
	}
	//유령이 있는 경우
	else if (v[row][col] == 3) {
		pair<int, int> dir = find_direction(direction);
		p.first += 1;
		p.second += distance;
		pair<int, int> val = find(row + dir.first, col + dir.second, direction, v, distance + 1);
		p.first += val.first;
		p.second += val.second;
		return p;
	}
	//  /인 경우
	else if (v[row][col] == 1) {
		switch (direction) {
		case 'U':
			direction = 'R';
			break;
		case 'D':
			direction = 'L';
			break;
		case 'L':
			direction = 'D';
			break;
		case 'R':
			direction = 'U';
			break;
		}
		pair<int, int> dir = find_direction(direction);
		pair<int, int> val = find(row + dir.first, col + dir.second, direction, v, distance + 1);
		p.first += val.first;
		p.second += val.second;
		return p;
	}
	// \인 경우
	else {
		switch (direction) {
		case 'U':
			direction = 'L';
			break;
		case 'D':
			direction = 'R';
			break;
		case 'L':
			direction = 'U';
			break;
		case 'R':
			direction = 'D';
			break;
		}
		pair<int, int> dir = find_direction(direction);
		pair<int, int> val = find(row + dir.first, col + dir.second, direction, v, distance + 1);
		p.first += val.first;
		p.second += val.second;
		return p;
	}


}









int main()
{
	cin >> N >> M >> K >> Q;

	vector<vector<int>> v(N + 1, vector<int>(M + 1, 0));


	int temp1, temp2;
	char c;
	for (int i = 0; i < K; i++) {
		cin >> temp1 >> temp2 >> c;
		if (c == '/')
			v[temp1][temp2] = 1;
		else if (c == '\\')
			v[temp1][temp2] = 2;
		else
			v[temp1][temp2] = 3;

	}

	while (Q--) {
		string str;
		cin >> str;

		int where = atoi(str.substr(1).c_str());
		char direction = str.front();
		pair<int, int> ans;
		switch (direction) {
		case 'U':
			direction = 'D';
			ans = find(1, where, direction, v);
			break;
		case 'D':
			direction = 'U';
			ans = find(N, where, direction, v);
			break;
		case 'L':
			direction = 'R';
			ans = find(1, where, direction, v);
			break;
		case 'R':
			direction = 'L';
			ans = find(where, M, direction, v);
			break;
		}

		cout << ans.first << ' ' << ans.second << endl;

	}







	return 0;
}