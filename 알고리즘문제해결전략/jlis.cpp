//��Ǯ� å����...
/*
cache[i][j]�� A���� i, B���� j���� �����ϴ� �� �����κм����� JLIS���� �����Ѵ�.

�ִ� ���� �κм����� [�ּҰ�1, �ּҰ�2, ....]�� �����Ѵ�.
��, �⺻���� 2���� �ְ� �ϱ� ������ ret�� 2�� ���´�.
�׷��� ���ο��� -2�� ����� ������ ���� ������ �ȴ�.

max(a,b)�� ���ϴ� ������, �ߺ��� �� (a���� 4 , b���� 4)��ü�� ���� �ʰ� ����ϱ� ����

�����ϴ� ���̸� Ű����....





*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long UNDEFINED = std::numeric_limits<long long>::min();

int A_sequence[101], B_sequence[101];
int cache[101][101];      //cache[i][j] : A���� i���� �����ϴ� ������, B���� j���� �����ϴ� ������ JLIS�� ����.

void init(int N, int M)
{
	//A���� �� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		cin >> A_sequence[i];

	}
	//B���� �� �ʱ�ȭ
	for (int i = 0; i < M; i++) {
		cin >> B_sequence[i];

	}
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			cache[i][j] = -1;

}

int JLIS(int A_idx, int B_idx, int N, int M)
{
	int & ret = cache[A_idx + 1][B_idx + 1];

	if (ret != -1)
		return ret;

	ret = 2;
	long long a = (A_idx == -1 ? UNDEFINED : A_sequence[A_idx]);
	long long b = (B_idx == -1 ? UNDEFINED : B_sequence[B_idx]);
	long long maxElement = max(a, b);

	for (int i = A_idx + 1; i < N; i++)
		if (maxElement < A_sequence[i])
			ret = max(ret, JLIS(i, B_idx, N, M)+1);

	for (int i = B_idx + 1; i < M; i++)
		if (maxElement < B_sequence[i])
			ret = max(ret, JLIS(A_idx, i, N, M) + 1);
	return ret;

}





int main()
{

	int C;
	cin >> C;
	while (C--)
	{
		
		int N, M; //A,B����
		cin >> N >> M;
		init(N, M);
		cout << JLIS(-1, -1, N, M) -2 << endl;
		



	}

	return 0;
}





























