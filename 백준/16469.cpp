#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

vector <string> mat;
vector <pair<int, int>> villain;

int cache[3][102][102];
int R, C;
int minArea[102][102];

void makeMinPath(const int villNum, int row, int col) {
	queue< pair<int , pair<int,int>>> Q;

	int visit[102][102];
	for (int i = 0; i <= R+1; i++) {
		for (int j = 0; j <= C+1; j++) {
			visit[i][j] = -1;
		}
	}
	


	int minPath = 0;
	Q.push({ minPath, {row,col} });

	while (!Q.empty()) {
		pair<int, pair<int, int>> p = Q.front();
		row = p.second.first;
		col = p.second.second;
		Q.pop();

		cache[villNum][row][col] = p.first;

		//�����¿�� �� �� �ִ��� Ȯ�� �� �� �� ������ ť�� Ǫ��
		//ĳ���� ����ִ� ��쿡��
		//1:��
		if (visit[row+1][col] == -1) {
			visit[row + 1][col] = 1;
			if (mat[row + 1][col] != '1' && cache[villNum][row + 1][col] == -1) {
				Q.push({ p.first + 1, {row + 1, col} });
			}
		}
		//2:��

		if (visit[row - 1][col] == -1) {
			visit[row - 1][col] = 1;
			if (mat[row - 1][col] != '1' && cache[villNum][row - 1][col] == -1) {
				Q.push({ p.first + 1, {row - 1, col} });
			}
		}
		//3:��

		if (visit[row][col - 1] == -1) {
			visit[row][col - 1] = 1;
			if (mat[row][col - 1] != '1' && cache[villNum][row][col - 1] == -1) {
				Q.push({ p.first + 1, {row, col - 1} });
			}
		}

		//4:��
		if (visit[row][col + 1] == -1) {
			visit[row][col + 1] = 1;
			if (mat[row][col + 1] != '1' && cache[villNum][row][col + 1] == -1) {
				Q.push({ p.first + 1, {row, col + 1} });
			}
		}
	}
	return;
}

int findMinTime() {
	//ĳ�ÿ� �Ҵ�
	for (int i = 0; i < 3; i++) {
		makeMinPath(i, villain[i].first, villain[i].second);
	}
	int minValue = 10000;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			//�ϳ��� ���̶� -1�״���� ��� ->�װ����� ���� �� ����
			int maxValue = -1;
			for (int k = 0; k < 3; k++) {
				if (cache[k][i][j] == -1) {
					maxValue = -1;
					break;
				}
				else {
					maxValue = max(maxValue, cache[k][i][j]);

				}
			}
			minArea[i][j] = maxValue;

			if (maxValue != -1)
				minValue = min(minValue, maxValue);	
		}
	}

	if (minValue == 10000)
		return -1;
	else
		return minValue;
}

int minAreaNum(int minTime) {
	
	int num = 0;
	/*
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << minArea[i][j] << ' ';
		}
		cout << endl;
	}*/


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(minArea[i][j] == minTime)
				num++;	
		}
	}
	
	return num;
	
}





int main()
{

	cin >> R >> C;


	string preStr = "1";
	for (int i = 0; i <= C; i++)
		preStr += "1";

	//�ֺ��� 1�� ���Ƶд�.
	mat.push_back(preStr);
	for (int i = 0; i < R; i++) {
		string temp = "1";
		string temp2;
		cin >> temp2;
		temp += temp2;
		temp += "1";
		mat.push_back(temp);
	}
	mat.push_back(preStr);

	/*
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}*/



	for (int i = 0; i < 3; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		villain.push_back({ temp1, temp2 });
	}
	//ĳ���ʱ�ȭ
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= R; j++) {
			for (int k = 0; k <= C; k++) {
				cache[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i <= R+1; i++)
		for (int j = 0; j <= C+1; j++)
			minArea[i][j] = -1;

	int minTime = findMinTime();
	cout << minTime<<endl;
	if(minTime != -1)
		cout << minAreaNum(minTime);
	/*
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= R; j++) {
			for (int k = 0; k <= C; k++) {
				cout<<cache[i][j][k]<<' ';
			}
			cout << endl;
		}
		cout << endl << endl;
	}*/
	


	return 0;
}