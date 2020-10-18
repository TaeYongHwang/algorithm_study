//왼쪽의 역순과 오른쪽의 최대 부분수열의 길이를 구한다. L
//(왼쪽의 크기 - L) + (오른쪽의 크기 -L)을 한 것이 결국 답이 될 것.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[5001][5001]; //cache[i][j] : i의시작으로 왼쪽으로, j시작으로 오른쪽으로 확장하는 두 배열의 겹친 최대수열의 크기
vector<int> arr;
int N;


//left right로 나누지 말고
//인덱싱을 잘 조절해서 해보는 방식 생각해보자.
//처음에 leftIdx는 leftMax로 시작, 0으로 내려가게
// rightIdx는 M으로시작 끝으로 올라가게,
int findMaxLen(int leftIdx, int rightIdx, const int leftMax, const int rightMax) {
	//범위초과
	if (leftIdx == -1 || rightIdx == N)
		return 0;


	int & ret = cache[leftIdx][rightIdx];

	if (ret != -1)
		return ret;
	
	//basecase 둘다끝에도달

	if (leftIdx == 0 && rightIdx == rightMax) {
		if (arr[leftIdx] == arr[rightIdx])
			return ret = 1;
		else
			return ret = 0;
	}
	//basecase 하나가 끝에 도달
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


	//값이 같은 경우
	if (arr[leftIdx] == arr[rightIdx]) {
		ret = 1 + findMaxLen(leftIdx -1, rightIdx + 1, leftMax, rightMax);
	}
	//같이 다른 경우
	else {
		ret = max(findMaxLen(leftIdx -1, rightIdx, leftMax, rightMax),
			findMaxLen(leftIdx, rightIdx + 1, leftMax, rightMax));

	}

	return ret;
}


void findMin(int N, int M) {
	
	int count = 0; //겹치는 갯수의 최대값.
	int leftMax; //왼쪽 수열의 최대 max idx 즉, M-1을 저장
	int rightMax; // 오른쪽 수열의 최대 max idx 즉, N-1을 저장


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

