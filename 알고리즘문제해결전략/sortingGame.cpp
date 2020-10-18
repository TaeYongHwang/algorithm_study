//BFS함수 사용시 시간 초과
//->각 숫자들을 작은 순서대로 1~N의 숫자로 치환
//->원래 정렬된 형태에서 해당 형태로 가는 최소거리 즉, No weight 무향 그래프에서의
//최소패스찾는 문제로 변경이 가능함

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N;

int bfs(const vector<int>& origin) {
	const int size = origin.size();
	vector<int> ans = origin;
	sort(ans.begin(), ans.end());
	
	queue<vector<int>> Q;
	map<vector<int>, int> distance;
	distance[origin] = 0;
	Q.push(origin);
	while (!Q.empty()) {
		vector<int> here = Q.front();
		Q.pop();

		if (here == ans)
			return distance[here];

		int cost = distance[here];

		for (int i = 0; i < N; i++) {
			for (int j = i + 2; j <= N; j++) {
				reverse(here.begin() + i, here.begin() +j );
				if (distance.count(here) == 0) {
					distance[here] = cost + 1;
					Q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);

			}
		}


	}
	return -1;
}


//정렬된 상태에서 다른 점들까지의 거리를 map에저장
map<vector<int>, int> preCalc()
{
	map<vector<int>, int> dist;
	vector<int> sorted;
	queue<vector<int>> Q;

	for (int i = 1; i <= 8; i++) { //i는 vector의 size
		sorted.push_back(i);
		Q.push(sorted);
		dist[sorted] = 0;
		while (!Q.empty()) {
			vector<int> here = Q.front();
			Q.pop();			
			int cost = dist[here];
			//모든 경우에대해 bfs
			for (int j = 0; j < i; j++) {
				for (int k = j + 2; k <= i; k++) {
					reverse(here.begin() + j, here.begin() + k);
					if (dist.count(here) == 0) {
						dist[here] = cost + 1;
						Q.push(here);
					}
					reverse(here.begin() + j, here.begin() + k);
				}
			}
		}
	}
	return dist;
}

//origin벡터를 크기값 (1~N)으로변경
vector<int> convert(vector<int> origin)
{
	vector<int> converted = vector<int>(N,0);
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (origin[i] > origin[j])
				count++;
		}
		converted[i] = count+1;
	
	}
	/*
	for (int i = 0; i < N; i++)
		cout << converted[i] << ' ';
	cout << endl;
	*/
	return converted;

}








int main()
{
	int C;
	cin >> C;
	map<vector<int>, int> ansMap = preCalc();
	while (C--) {
		cin >> N;
		vector<int> origin;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			origin.push_back(temp);
		}
	

		cout << ansMap[convert(origin)] << endl;




	}
	return 0;
}