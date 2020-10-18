#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, K; //N개의 수열의 부분수열 중 합이 K인 구간의 수를 출력.
long long cur_number;
int onOff = 0;

int find_next_number()
{
	//맨처음만 그냥 반환시키기위해
	if (onOff == 0) {
		onOff= 1;
		return cur_number;
	}


	long long mod = pow(2, 32);
	
	//현재값 갱신
	cur_number = (cur_number * 214013 + 2531011) % mod;

	//입력 신호값
	int temp = cur_number % 10000 + 1;


	return temp;
}

int find_all_cases() {
		queue <int> Q;
		int sum = 0;
		int count = 0;
		

		while (N ) {
		//	cout << N << endl;

			//원하는  숫자보다 작은경우 : 값을 sum에 더 더해줘야한다.
			if (sum < K) {


				int temp = find_next_number();
				sum += temp;
				Q.push(temp);
				N--;


				continue;
			}

			//원하는 숫자보다 큰경우 : 처음 값을 빼주고 다시 계산해본다.
			else if (sum > K) {
		
				int front = Q.front();
				Q.pop();
				sum -= front;
				continue;
			}
			//동일한 경우 :count를 1 늘린 후 값을 빼주고 다시 돌린다.
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