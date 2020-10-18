//������ ������ �������� �ִ� �κм����� ���̸� ���Ѵ�. L
//(������ ũ�� - L) + (�������� ũ�� -L)�� �� ���� �ᱹ ���� �� ��.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[5001][5001]; //cache[i][j] : i�ǽ������� ��������, j�������� ���������� Ȯ���ϴ� �� �迭�� ��ģ �ִ������ ũ��
vector<int> arr;
int N;


//left right�� ������ ����
//�ε����� �� �����ؼ� �غ��� ��� �����غ���.
//ó���� leftIdx�� leftMax�� ����, 0���� ��������
// rightIdx�� M���ν��� ������ �ö󰡰�,
int findMaxLen(int leftIdx, int rightIdx, const int leftMax, const int rightMax) {
	//�����ʰ�
	if (leftIdx == -1 || rightIdx == N)
		return 0;


	int & ret = cache[leftIdx][rightIdx];

	if (ret != -1)
		return ret;
	
	//basecase �Ѵٳ�������

	if (leftIdx == 0 && rightIdx == rightMax) {
		if (arr[leftIdx] == arr[rightIdx])
			return ret = 1;
		else
			return ret = 0;
	}
	//basecase �ϳ��� ���� ����
	if (leftIdx == 0) {
		if (arr[leftIdx] == arr[rightIdx])
			return ret = 1;
		else
			return ret =findMaxLen(leftIdx, rightIdx+1, leftMax, rightMax);

	}
	else if (rightIdx == rightMax) {
		if (arr[leftIdx] == arr[rightIdx])
			return ret = 1;
		else
			return ret =findMaxLen(leftIdx-1, rightIdx, leftMax, rightMax);

	}


	//���� ���� ���
	if (arr[leftIdx] == arr[rightIdx]) {
		ret = 1 + findMaxLen(leftIdx -1, rightIdx + 1, leftMax, rightMax);
	}
	//���� �ٸ� ���
	else {
		ret = max(findMaxLen(leftIdx -1, rightIdx, leftMax, rightMax),
			findMaxLen(leftIdx, rightIdx + 1, leftMax, rightMax));

	}

	return ret;
}


void findMin(int N, int M) {
	
	int count = 0; //��ġ�� ������ �ִ밪.
	int leftMax; //���� ������ �ִ� max idx ��, M-1�� ����
	int rightMax; // ������ ������ �ִ� max idx ��, N-1�� ����


	leftMax = M - 2;
	rightMax = N - 1;

	
	count = findMaxLen(leftMax, M, leftMax, rightMax);

	//cout << "Count : " << count << endl;
	cout << N-1 - (2 * count) << endl;
	


	return;
}




int main()
{
	int T,M;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> T;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cache[i][j] = -1;
		}
	}
	while (T--) {
		cin >> M;
		findMin(N, M);
		/*
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				cout<< cache[i][j]<<' ';
			}
			cout << endl;
		}
		*/
	}


	return 0;
}

