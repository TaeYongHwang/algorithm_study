#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, K; //N���� ������ �κм��� �� ���� K�� ������ ���� ���.
long long cur_number;
int onOff = 0;

int find_next_number()
{
	//��ó���� �׳� ��ȯ��Ű������
	if (onOff == 0) {
		onOff= 1;
		return cur_number;
	}


	long long mod = pow(2, 32);
	
	//���簪 ����
	cur_number = (cur_number * 214013 + 2531011) % mod;

	//�Է� ��ȣ��
	int temp = cur_number % 10000 + 1;


	return temp;
}

int find_all_cases() {
		queue <int> Q;
		int sum = 0;
		int count = 0;
		

		while (N ) {
		//	cout << N << endl;

			//���ϴ�  ���ں��� ������� : ���� sum�� �� ��������Ѵ�.
			if (sum < K) {


				int temp = find_next_number();
				sum += temp;
				Q.push(temp);
				N--;


				continue;
			}

			//���ϴ� ���ں��� ū��� : ó�� ���� ���ְ� �ٽ� ����غ���.
			else if (sum > K) {
		
				int front = Q.front();
				Q.pop();
				sum -= front;
				continue;
			}
			//������ ��� :count�� 1 �ø� �� ���� ���ְ� �ٽ� ������.
			else {

				count++;
				int front = Q.front();
				Q.pop();
				sum -= front;
				continue;
			}




		}

		return count;

}




int main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> K >> N;		
		cur_number = 1983;
	

		cout << find_all_cases() << endl;



	}

	return 0;
}