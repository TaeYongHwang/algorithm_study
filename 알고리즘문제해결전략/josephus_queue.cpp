#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;

void remain_two(int num, queue<int>& Q) {
	
	if (Q.size() == 2)
		return;

	//맨앞 한명 죽임
	Q.pop();

	//k-1번 반복
	for (int i = 1; i <= K - 1; i++) {
		int temp = Q.front();
		Q.pop();
		Q.push(temp);
	}

	remain_two(num - 1, Q);

	return;

}



int main()
{
	int C;
	cin >> C;

	queue <int> Q;
	while (C--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			Q.push(i);
	
		remain_two(N, Q);

		
		int temp1 = Q.front();
		Q.pop();
		int temp2 = Q.front();
		Q.pop();

		if (temp1 > temp2)
			cout << temp2 << ' ' << temp1 << endl;
		else
			cout << temp1 << ' ' << temp2 << endl;




	}

	return 0;
}