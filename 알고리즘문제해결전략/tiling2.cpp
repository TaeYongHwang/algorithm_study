#include <iostream>

using namespace std;

int cache[101]; //cache[i] : 2xiũ�⸦ ��ƴ���� ä��� ��� ����� �� (%100000007����)


int find_all_cases(int N)
{
	int &ret = cache[N];
	
	//basecase 0 : �̹� ����� ��
	if (ret != -1)
		return ret;

	//basecase N== 1 �� ���
	if (N == 1)
		return ret = 1;
	if (N== 2)
		return ret = 2;

	int sum = 0;

	sum += find_all_cases(N - 1) % 1000000007;
	sum +=  find_all_cases(N - 2) % 1000000007;
	

	return ret = sum % 1000000007;


}




int main()
{
	int C;
	cin >> C;

	while (C--) {
		int N;
		cin >> N;
		for (int i = 0; i <= 101; i++)
			cache[i] = -1;

		cout << find_all_cases(N) << endl;



	}
	return 0;
}


