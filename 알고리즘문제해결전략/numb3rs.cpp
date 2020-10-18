#include <iostream>
#include <algorithm>
using namespace std;

int N, D;  //N : ���� ��[0,N)  , D: ���� �ϼ�
int P;// �����Ұ� �ִ� ����

int path[50][50];   //[i][j] : ������ ���� ����.
int path_count[50]; //i���� ����� ���� ��
double cache[101][50]; //cache[i][j] : i��(�ڿ���)���� �Ŀ�, j��[0,N) ������ ���� Ȯ��.

void init() {

	for (int i = 0; i < N; i++) {
		path_count[i] = 0;
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> path[i][j];
			if (path[i][j] == 1)
				path_count[i] ++;

		}
	}

	for (int i = 0; i <= D; i++) {
		for (int j = 0; j < N; j++) {
			cache[i][j] = -1;
		}
	}

}

double find_prob(int day, int city)
{
	
	//basecase 1 : day�� 0�� ��
	if (day == 0) {
		if (city == P)
			return 1;
		else
			return 0;

	}
	
	double & ret = cache[day][city];

	//basecase 2 : ����� ���
	if (ret != -1)
		return ret;


	
	double sum = 0;
	
	for (int i = 0; i < N; i++) {
		if (path[city][i] == 1) {//����� ���
			//count�� �ش� ���� �ƴ� ������ִ� ���� �������� �ؾߵ�(������ ã�ư��°ű⋚��)
			const int& count = path_count[i];
			sum += find_prob(day - 1, i) / count;

		}
	}
	
	return ret = sum;

}













int main()
{
	cout.precision(8);
	int C;
	cin >> C;
	while (C--) {
		cin >> N >> D >> P;

		init();
		
		int num;
		cin >> num;
		while (num--) {
			int temp;
			cin >> temp;
			
			cout << find_prob(D, temp) << ' ';

		}
		cout << endl;







	}
	return 0;
}