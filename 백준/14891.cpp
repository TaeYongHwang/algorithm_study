#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

vector<string> gears;

void rotateG(int idx, bool dir, vector<bool>& visited) {
	//dir ==1 : 시계
	//dir == -1 : 반시계
	
	visited[idx] = true;

	//왼쪽 톱니바퀴 돌릴지말지
	if (idx - 1 >= 0 && !visited[idx-1]) {
		
		if (gears[idx - 1][2] != gears[idx][6]) {
			rotateG(idx - 1, !dir, visited);
		}
	}
	//오른쪽 돌릴지말지
	if (idx + 1 < 4 && !visited[idx + 1]) {
	
		if (gears[idx + 1][6] != gears[idx][2]) {
			rotateG(idx + 1, !dir, visited);
		}

	}

	//실제로 돌리는 함수
	if (dir) { //시계
		string str = "";
		str.push_back(gears[idx][7]);
		for (int i = 0; i < 7; i++) {
			str.push_back(gears[idx][i]);
		}
		gears[idx] = str;

	}
	else { //반시계
		string str = "";
		for (int i = 1; i < 8; i++) {
			str.push_back(gears[idx][i]);
		}
		str.push_back(gears[idx][0]);
		gears[idx] = str;
	}

	return;
}




int main() {
	
	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		gears.push_back(temp);
	}

	int K;
	cin >> K;
	while (K--) {
		vector<bool> visited = vector<bool>(4, false);
		int num, dir;
		cin >> num>> dir;
		if (dir == 1) {
			rotateG(num - 1, true, visited);
		}
		else {
			rotateG(num - 1, false, visited);
		}
		/*
		for (int i = 0; i < 4; i++) {
			cout << gears[i] << endl;
		}
		*/

	}



	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gears[i][0] == '1')
			ans += pow(2, i);
	}

	cout << ans << endl;





	return 0;
}