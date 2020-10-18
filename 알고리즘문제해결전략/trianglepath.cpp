#include <iostream>
#include <algorithm>

using namespace std;

int triangle[100][100];
int cache[100][100]; //cache[i][j] = triangle[i][j]에서 갖을 수 있는 최대합
					 //즉, 우리가 구하려는 값은 cache[0][0]에 저장돼있다.

void init(int N) //N크기만큼 triangle과 cache를 초기화(cache는 -1로)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
			cache[i][j] = -1;
		}
	}
}

int max_sum(int N, int row =0, int col = 0)
{
	int &ret = cache[row][col];

	//basecase 1 : 이미 캐시에 값이 찬 경우
	if (ret != -1)
		return ret;

	//basecase 2 : 맨 아랫줄에 도달한 경우
	if (row == N - 1)
		return ret = triangle[row][col];


	//아래로 가는 경우와, 아래오른쪽으로 가는 경우 각각 중 더 큰값에, 현재속해있는 값을 더해줌
	int sum;
	sum = triangle[row][col] + max(max_sum(N, row + 1, col), max_sum(N, row + 1, col + 1));

	return ret = sum;

}




int main()
{
	int C;
	cin >> C;

	while (C--)
	{ 
		int N; //삼각형 크기
		cin >> N;
		init(N);
		max_sum(N);
		cout << cache[0][0] << endl;


	}



	return 0;
}