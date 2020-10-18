#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M; // n : ����, m : �ϼ�

double cache[1001][1001]; //cache[i][j] : i�� ���Ұ�, j���� ���� ��쿡 ������ ���ް����� Ȯ��.
					   //i,j�� �ᱹ �ڿ��� -> 0�������ϴ� ��쿡 ����ó��.
						//Ȯ���� �����ϴ� ���̱� ������, ��� ��쿡 ������ ��� 1�� ����,
						//��� ��쿡 ������ ��� 0�� ���� ����Ǵ� ����

double find_possible_cases(int row, int col)
{
	cout.precision(10);
	double & ret = cache[row][col];

	//basecase 1 :������ �������
	if (row == 0) {
		//���̰� ���� �������
		if (col > 0)
			return ret = 0;
		//���̰� ���� ���
		else
			return cache[0][0] = 1;
	}


	//basecase 2 : ���̰� ���� ���
	if (col == 0 || col == 1) {
		return ret = 1;
	}




	//basecase 3 : �̹� ����� ���
	if (ret != -1)
		return ret;

	//����� ���� 3�� ����ġ�� �༭ ����� ���� ����
	double sum = 0;
	//����� ��
	sum += 0.75*find_possible_cases(row - 1, col - 2);
	//�� �ȿ��� ��
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