//���
/*
1. �� ������ �����ִ� ���̸� ���� Ȯ���� �� �ִ� ���� ū ���̸� ���� (�ִ�n^2, �ּ� n)
   ->��, �ڱ⺸�� ���� �潺�����δ� Ȯ���Ű�� �ʴ´�.
2. �� ������ �� (n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fence[20000];
int N;

//�ش� �ε�������, �ش� �ε����� ���̷� ���� �� �ִ� ���� ���� ���簢���� ����.
int find_max_square(int idx)
{
	int height = fence[idx]; //�ش� �ε����� ����
	int leftIdx = idx;
	int rightIdx = idx;

	//�����ε����� height���� ���� ������ Ȯ��.
	while (leftIdx - 1 >= 0 && fence[leftIdx - 1] >= height)
		leftIdx--;

	//�������ε����� height���� ���� ������ Ȯ��.
	while (rightIdx + 1 < N && fence[rightIdx + 1] >= height)
		rightIdx++;


	return (rightIdx - leftIdx + 1) * height;

}

//�ùٸ� �� ������ ���� rapping function
int find_max()
{
	int  max_square = 0;
	for (int i = 0; i < N; i++) {
		max_square = max(max_square,find_max_square(i));
	}

	return max_square;
}




int main()
{
	int C;
	cin >> C;
	while (C--)
	{

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> fence[i];


		cout << find_max() << endl;




	}





	return 0;
}