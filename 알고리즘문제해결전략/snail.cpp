#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M; // n : 깊이, m : 일수

double cache[1001][1001]; //cache[i][j] : i일 남았고, j미터 남은 경우에 끝까지 도달가능한 확률.
					   //i,j는 결국 자연수 -> 0에도달하는 경우에 따로처리.
						//확률을 저장하는 것이기 때문에, 모든 경우에 성공할 경우 1의 값이,
						//모든 경우에 실패할 경우 0의 값이 저장되는 원리

double find_possible_cases(int row, int col)
{
	cout.precision(10);
	double & ret = cache[row][col];

	//basecase 1 :기한이 끝난경우
	if (row == 0) {
		//길이가 아직 남은경우
		if (col > 0)
			return ret = 0;
		//길이가 끝난 경우
		else
			return cache[0][0] = 1;
	}


	//basecase 2 : 길이가 끝난 경우
	if (col == 0 || col == 1) {
		return ret = 1;
	}




	//basecase 3 : 이미 계산한 경우
	if (ret != -1)
		return ret;

	//비오는 날에 3의 가중치를 줘서 경우의 수를 구함
	double sum = 0;
	//비오는 날
	sum += 0.75*find_possible_cases(row - 1, col - 2);
	//비 안오는 날
	sum += 0.25*find_possible_cases(row - 1, col - 1);


	return ret = sum;

}






int main()
{
	int C;
	cin >> C;

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			cache[i][j] = -1;
		}
	}

	while (C--)
	{
		cin >> N >> M;



		cout << find_possible_cases(M, N) << endl;



	}


	return 0;
}