#include <iostream>

using namespace std;

int cache[100][100]; // cache[i][j] : i,j에서 끝에 도달하는 방법이 존재하는지 
				    //  -1 : 아직 안들어가봄
					//  0  : 없다
					//  1  : 있다.
int board[100][100];

// 없 : 0 , 있 : 1
int is_end_case(int row, int col, int N)
{
	int &ret = cache[row][col];

	//이미 한 번 ㄱㅖ산한 경우
	if (ret != -1)
		return ret;

	//기저사례 : 마지막 점에 도달한 경우
	if (board[row][col] == 0)
		return ret = 1;

	//범위 내에 속하면은 분기할 수 있게
	//case 1 : 오른쪽
	if (col + board[row][col] < N) {
		if (is_end_case(row, col + board[row][col], N))
			return ret = 1;

	}

	//case 2 : 아래
	if (row + board[row][col] < N) {
		if (is_end_case(row + board[row][col], col, N))
			return ret = 1;
	}
	

	return ret = 0;

}




int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0 ; j <N; j++) {
				cache[i][j] = -1;
				cin >> board[i][j];
			}
		}


		if (is_end_case(0, 0, N))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;



	}




	return 0;
}