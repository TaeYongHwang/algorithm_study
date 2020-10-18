/*
���� ���� �̿�
: case 1 : ������ �������� ��, ���ʿ� ����
  case 2 : ������ �������� ��, �����ʿ� ����
  case 3 : �߰��� ���ļ� ����.
  
  �ð� ���⵵ : O(nlgn)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int fence[20000];

int find_max(const int left = 0, const int right = N) //[)������
{
	int max_square = 0;
	int mid = (left + right) / 2;

	//�� �̻� ���� �� ���� ���. (���� �ϳ��ۿ� �������� �ʴ� ���)
	if (left == right - 1)
		return fence[left];


	//case 1 : ���ʿ� ����.
	max_square = max(max_square, find_max(left, mid));

	//case 2 : �����ʿ� ����.
	max_square = max(max_square, find_max(mid, right));

	//case 3 : ���ʿ� ���ļ� ����.(mid-1�� mid�� ���ļ�����)
	//�ش� ���� [left,right)����, ���� ���� �簢�� ��ȯ.
	int height = min(fence[mid - 1], fence[mid]);
	int width = 2;
	int square = width * height; //�ϴ� �⺻ �簢���� ũ�Ⱑ ������ �ȴ�.

	//��,������ �߿� �� ���� ������ Ȯ���Ų��.
	int leftIdx = mid - 1;
	int rightIdx = mid;

	while (leftIdx - 1 >= left && rightIdx + 1 < right)
	{
		if (fence[leftIdx - 1] > fence[rightIdx + 1]) {
			if (fence[leftIdx - 1] < height)
				height = fence[leftIdx - 1];
			width++;
			square = max(square, width*height);
			leftIdx--;
		}
		else {
			if (fence[rightIdx + 1] < height)
				height = fence[rightIdx + 1];
			width++;
			square = max(square, width*height);
			rightIdx++;
		}
	}
	//�� �� �� ���� ���� ����� ���.

	if (leftIdx - 1 >= left) {
		while (leftIdx - 1 >= left)
		{
			if (fence[leftIdx - 1] < height)
				height = fence[leftIdx - 1];
			width++;
			square = max(square, width*height);
			leftIdx--;

		}
	} 
	if (rightIdx + 1 < right) {
		while (rightIdx + 1 < right)
		{
			if (fence[rightIdx + 1] < height)
				height = fence[rightIdx + 1];
			width++;
			square = max(square, width*height);
			rightIdx++;

		}
	}




	return  max_square = max(max_square, square);
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