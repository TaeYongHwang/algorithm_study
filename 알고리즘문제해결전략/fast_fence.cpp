/*
분할 정복 이용
: case 1 : 반으로 나누었을 때, 왼쪽에 존재
  case 2 : 반으로 나누었을 때, 오른쪽에 존재
  case 3 : 중간에 걸쳐서 존재.
  
  시간 복잡도 : O(nlgn)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int fence[20000];

int find_max(const int left = 0, const int right = N) //[)범위로
{
	int max_square = 0;
	int mid = (left + right) / 2;

	//더 이상 나눌 수 없는 경우. (값이 하나밖에 존재하지 않는 경우)
	if (left == right - 1)
		return fence[left];


	//case 1 : 왼쪽에 존재.
	max_square = max(max_square, find_max(left, mid));

	//case 2 : 오른쪽에 존재.
	max_square = max(max_square, find_max(mid, right));

	//case 3 : 양쪽에 걸쳐서 존재.(mid-1과 mid에 걸쳐서존재)
	//해당 범위 [left,right)에서, 가장 넓은 사각형 반환.
	int height = min(fence[mid - 1], fence[mid]);
	int width = 2;
	int square = width * height; //일단 기본 사각형의 크기가 이정도 된다.

	//왼,오른쪽 중에 더 높은 쪽으로 확장시킨다.
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
	//둘 중 한 쪽이 먼저 종료된 경우.

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