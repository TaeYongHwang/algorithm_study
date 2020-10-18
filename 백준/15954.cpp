#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

long double standardDeviation(int start ,int end, int k) {
//	cout << '[' << start << ',' << end <<','<< k<<']' << endl;
	long double mean = 0;
	long double ans = 0;

	for (int i = start; i < end; i++) {
		mean += v[i];
	}
	mean /= k;
	
	for (int i = start; i < end; i++) {
		ans += pow(v[i] - mean, 2);
	}
	
	/*
	long double temp = 0;
	for (int i = start; i < end; i++) {
		ans += v[i]*v[i];
		temp += v[i];
	}
	ans -= 2 * mean *temp;
	ans += mean * mean* k;
	*/

	ans /= k;

	return sqrt(ans);
}


int main() {
	cout.precision(8);

	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	long double ans = 99999999999999;

	for (int i = 0; i < N - K+1; i++) {
		int count = K;
		while (count <= N - i ) {
			//cout << '[' << i << ',' << i+count << ']' << endl;
			ans = min(ans, standardDeviation(i, i + count, count));
			count++;
		}
	}
	
	cout << ans << endl;



	return 0;
}