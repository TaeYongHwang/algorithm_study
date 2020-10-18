//방식
/*
1. 각 점에서 갖고있는 높이를 갖고 확장할 수 있는 가장 큰 넓이를 저장 (최대n^2, 최소 n)
   ->즉, 자기보다 작은 펜스쪽으로는 확장시키지 않는다.
2. 그 값들을 비교 (n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fence[20000];
int N;

//해당 인덱스에서, 해당 인덱스의 높이로 만들 수 있는 가장 넓은 직사각형을 구함.
int find_max_square(int idx)
{
	int height = fence[idx]; //해당 인덱스의 높이
	int leftIdx = idx;
	int rightIdx = idx;

	//왼쪽인덱스가 height보다 낮을 때까지 확장.
	while (leftIdx - 1 >= 0 && fence[leftIdx - 1] >= height)
		leftIdx--;

	//오른쪽인덱스가 height보다 낮을 때까지 확장.
	while (rightIdx + 1 < N && fence[rightIdx + 1] >= height)
		rightIdx++;


	return (rightIdx - leftIdx + 1) * height;

}

//올바른 값 도출을 위한 rapping function
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