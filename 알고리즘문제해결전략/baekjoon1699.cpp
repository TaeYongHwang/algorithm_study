#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int cache[100001];

int findMinCount(int N) {
	int &ret = cache[N];

	//basecases.
	if (ret != -1)
		return ret;
	if (N == 0)
		return ret = 0;
	else if (N == 1)
		return ret = 1;



	ret = 100000;

	int sqrtValue = sqrt(N);
	
	for (int i = sqrtValue; i > 0; i--) {

		ret = min(ret, findMinCount(N - (i*i)) + 1);

	}
	
	return ret;
}



int main()
{
	int N;
	cin >> N;

	for (int i = 0; i <= N; i++)
		cache[i] = -1;

	cout << findMinCount(N);
/*
	for (int i = 1; i <= N; i++)
		cout << cache[i] << endl;
	cout << endl;
	*/

	return 0;
}