#include <iostream>
#include <algorithm>
using namespace std;

int N, D;  //N : 마을 수[0,N)  , D: 지난 일수
int P;// 교도소가 있는 마을

int path[50][50];   //[i][j] : 마을의 연결 상태.
int path_count[50]; //i번에 연결된 마을 수
double cache[101][50]; //cache[i][j] : i일(자연수)지난 후에, j번[0,N) 마을에 있을 확률.

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
	
	//basecase 1 : day가 0일 때
	if (day == 0) {
		if (city == P)
			return 1;
		else
			return 0;

	}
	
	double & ret = cache[day][city];

	//basecase 2 : 계산한 경우
	if (ret != -1)
		return ret;


	
	double sum = 0;
	
	for (int i = 0; i < N; i++) {
		if (path[city][i] == 1) {//연결된 경우
			//count를 해당 점이 아닌 연결돼있는 점을 기준으로 해야됨(역으로 찾아가는거기떄문)
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