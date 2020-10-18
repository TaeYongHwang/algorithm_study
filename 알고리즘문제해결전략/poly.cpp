#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 10000000;

int N;
int cache[101][101]; // cache[i][j] : i개가 존재할 때, 맨위 행에 존재하는 사각형 갯수가 j개인 폴리오미노의 수

//num : 전체개수, top : 맨위 갯수
//즉 N개에서 전체 경우의 수를 구하기 위해서는 top이 [1,N]범위를 모두 더해야 함.

int find_all_cases(int num, int top) {

	int & ret = cache[num][top];
	
	//basecase 0 : 이미 차있는 경우.
	if (ret != -1)
		return ret;

	//basecase 1 : 갯수가 하나 밖에 없는 경우. or 해당 열에 모든 갯수가 배치되는 경우
	if (num == 1 || (num==top))
		return ret = 1;

	
	int sum = 0;
	//맨 윗줄에 top개가 배치된 후
	//다음줄에 몇개가 배치될지
	for (int i = 1; i <= num - top; i++) {
		sum += (top + i - 1) *find_all_cases(num - top, i);
		sum %= MOD;
	}

	return ret = sum;

}

int wrapper()
{
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		sum += find_all_cases(N, i);
		sum %= MOD;
	}

	return sum % MOD;
}


int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> N;

		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				cache[i][j] = -1;


		cout << wrapper() << endl;
		/*
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << cache[i][j] << ' ';
			}
			cout << endl;
		}*/




	}
	return 0;
}