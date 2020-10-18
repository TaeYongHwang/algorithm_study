#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
vector<int> weight;

void findSum(int start, int end, int sum, vector<int>&v) {
	if (sum > C)
		return;
	if (start > end)
		return v.push_back(sum);

	findSum(start + 1, end, sum + weight[start], v);
	findSum(start + 1, end, sum, v);
}



int main()
{
	
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		weight.push_back(temp);
	}

	vector<int> v1; //앞의 15개에 대해 모든 경우의 sum을저장 
	findSum(0, N / 2 - 1, 0, v1);
	sort(v1.begin(), v1.end());
	vector<int> v2; //뒤의 15개에 대해 모든 경우의 sum을 저장
	findSum(N / 2, N-1,0, v2);
	sort(v2.begin(), v2.end());

	int ans = 0;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] + v2[j] <= C)
				ans++;
		}

	}
	cout << ans<<endl;




	return 0;


}