#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 10000000;

int N;
int cache[101][101]; // cache[i][j] : i���� ������ ��, ���� �࿡ �����ϴ� �簢�� ������ j���� �������̳��� ��

//num : ��ü����, top : ���� ����
//�� N������ ��ü ����� ���� ���ϱ� ���ؼ��� top�� [1,N]������ ��� ���ؾ� ��.

int find_all_cases(int num, int top) {

	int & ret = cache[num][top];
	
	//basecase 0 : �̹� ���ִ� ���.
	if (ret != -1)
		return ret;

	//basecase 1 : ������ �ϳ� �ۿ� ���� ���. or �ش� ���� ��� ������ ��ġ�Ǵ� ���
	if (num == 1 || (num==top))
		return ret = 1;

	
	int sum = 0;
	//�� ���ٿ� top���� ��ġ�� ��
	//�����ٿ� ��� ��ġ����
	for (int i = 1; i <= num - top; i++) {
		sum += (top + i - 1) *find_all_cases(num - top, i);
		sum %= MOD;
	}

	return ret = sum;

}

int wrapper()
{
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		sum += find_all_cases(N, i);
		sum %= MOD;
	}

	return sum % MOD;
}


int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> N;

		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				cache[i][j] = -1;


		cout << wrapper() << endl;
		/*
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << cache[i][j] << ' ';
			}
			cout << endl;
		}*/




	}
	return 0;
}