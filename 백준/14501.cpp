#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> days;
vector<int> prices;
vector<int> cache;

int dp(int idx) {
	
	int & ret = cache[idx];

	if (ret != -1)
		return ret;

	//basecase 1 :만약 필요할 day가 퇴사날을 넘기는 경우
	//0일부터 시작하게끔 바꿈.
	if (idx + days[idx] > N)
		return ret = 0;
	if (idx + days[idx] == N)
		return ret = prices[idx];


	for (int i = idx + days[idx]; i < N ; i++) {
		ret = max(ret, prices[idx] + dp(i));
	}
	
	return ret;

}





int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp1,temp2;
		cin >> temp1>>temp2;
		days.push_back(temp1);
		prices.push_back(temp2);
	}
	cache = vector<int>(N, -1);

	int maxV = -1;

	for (int i = 0; i < N; i++) {
		maxV = max(maxV, dp(i));
		//cout << "i :"<<i<<' ' << dp(i) << endl;
	}
	
	cout << maxV << endl;

	return 0;
}