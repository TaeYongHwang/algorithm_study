//그냥 BFS로 구현한 경우 -> 시간초과
//나중에 다익스트라로 해보자.

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int V, E;
vector<vector<pair<int,int>>> adj; //pair.first : 목적지, second : 웨이트

vector<int> findMin(int start)
{
	vector<bool> discovered = vector<bool>(V + 1, false);
	vector<int> shortestPath = vector<int>(V + 1, -1);
	queue<int> Q;
	
	discovered[start] = true;
	Q.push(start);
	shortestPath[start] = 0;

	while (!Q.empty()) {
		int here = Q.front();
		Q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			pair<int, int> there = adj[here][i];
			if (shortestPath[there.first] == -1)
				shortestPath[there.first] = shortestPath[here] + there.second;
			else
				shortestPath[there.first] = min(shortestPath[there.first], shortestPath[here] + there.second);

			if (discovered[there.first] == false)
				Q.push(there.first);
		}
	}
	
	return shortestPath;

}







int main()
{
	int start;
	cin >> V >> E >> start;

	adj = vector<vector<pair<int,int>>>(V + 1, vector<pair<int,int>>());

	for (int i = 0; i < E; i++) {
		int src, dst,w;
		cin >> src >> dst>>w;
		adj[src].push_back(make_pair(dst, w));
	}

	vector<int> shortest = findMin(start);
	for (int i = 1; i < shortest.size(); i++) {
		if (shortest[i] == -1)
			cout << "INF" << endl;
		else
			cout << shortest[i] << endl;
	}
	



	return 0;
}