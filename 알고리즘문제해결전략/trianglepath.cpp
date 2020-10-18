#include <iostream>
#include <algorithm>

using namespace std;

int triangle[100][100];
int cache[100][100]; //cache[i][j] = triangle[i][j]���� ���� �� �ִ� �ִ���
					 //��, �츮�� ���Ϸ��� ���� cache[0][0]�� ������ִ�.

void init(int N) //Nũ�⸸ŭ triangle�� cache�� �ʱ�ȭ(cache�� -1��)
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

	//basecase 1 : �̹� ĳ�ÿ� ���� �� ���
	if (ret != -1)
		return ret;

	//basecase 2 : �� �Ʒ��ٿ� ������ ���
	if (row == N - 1)
		return ret = triangle[row][col];


	//�Ʒ��� ���� ����, �Ʒ����������� ���� ��� ���� �� �� ū����, ��������ִ� ���� ������
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
		int N; //�ﰢ�� ũ��
		cin >> N;
		init(N);
		max_sum(N);
		cout << cache[0][0] << endl;


	}



	return 0;
}