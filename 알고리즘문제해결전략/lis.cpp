#include <iostream>
#include <algorithm>

using namespace std;

int sequence[500];
int cache[500]; //cache[i] : ���� �����ϴ� LIS��


void init(int N)
{
	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
		cache[i] = -1;
	}
}

int LIS(int N, int idx = 0) //�� ó���� N-1�� idx�� ���� ä�� ����.
{


	int &ret = cache[idx];

	//basecase 1 : idx�� N-1�� �� ���
	if (idx == N - 1)
		return ret = 1;


	//basecase 2 : �ش� ���� �̹� ä���� ���
	if (ret != -1)
		return ret;


	//[idx+1, N)�� ��ȸ�ϸ鼭, �ڽ��� ������ ���� ū���� ã�´�.
	int max_LIS = 0;
	for (int i = idx + 1; i < N; i++)
	{
		if (sequence[idx] < sequence[i]) {
			max_LIS = max(max_LIS, LIS(N, i) + 1);
		//	cout << max_LIS << endl;
		}
		else {
			LIS(N, i);
		}
	}
	if (max_LIS == 0)
		return ret = 1;
	else
		return ret = max_LIS;
}

int LIS_wrapper(int N)
{
	LIS(N);
	int max_LIS = 0;
	for (int i = 0; i < N; i++) {
		max_LIS = max(max_LIS, cache[i]);
	}
	return max_LIS;
}



int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int N;
		cin >> N;
		init(N);


		cout << LIS_wrapper(N) << endl;


	}

	return 0;
}


