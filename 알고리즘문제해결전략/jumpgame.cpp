#include <iostream>

using namespace std;

int cache[100][100]; // cache[i][j] : i,j���� ���� �����ϴ� ����� �����ϴ��� 
				    //  -1 : ���� �ȵ���
					//  0  : ����
					//  1  : �ִ�.
int board[100][100];

// �� : 0 , �� : 1
int is_end_case(int row, int col, int N)
{
	int &ret = cache[row][col];

	//�̹� �� �� ���ƻ��� ���
	if (ret != -1)
		return ret;

	//������� : ������ ���� ������ ���
	if (board[row][col] == 0)
		return ret = 1;

	//���� ���� ���ϸ��� �б��� �� �ְ�
	//case 1 : ������
	if (col + board[row][col] < N) {
		if (is_end_case(row, col + board[row][col], N))
			return ret = 1;

	}

	//case 2 : �Ʒ�
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