#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M; //정점, 간선 갯수

queue<int> Q;
bool visit[1001];
vector<vector<int>> adj; //인덱싱이 1부터.
vector<int> dfs_order;
vector<int> bfs_order;

void dfs(int idx) {
	visit[idx] = true;
	dfs_order.push_back(idx);



	for (int i = 0; i < adj[idx].size(); i++) {
		int there = adj[idx][i];
		if (visit[there] == false) {
			dfs(there);
			
		}
	}


	
	return;
}


void bfs(int idx) {

	Q.push(idx);
	visit[idx] = true;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		bfs_order.push_back(cur);

		for (int i = 0; i < adj[cur].size(); i++) {
			int there = adj[cur][i];
			if (visit[there] == false) {
				Q.push(there);
				visit[there] = true;
			}
		}

		
	}

	return;
}


void findAns(int idx)
{
	
	for (int i = 0; i <= N; i++)
		visit[i] = false;
	
	
	dfs(idx);

	for (int i = 0; i < dfs_order.size(); i++)
		cout << dfs_order[i] << ' ';
	cout << endl;


	for (int i = 0; i <= N; i++)
		visit[i] = false;
	bfs(idx);

	for (int i = 0; i < bfs_order.size(); i++)
		cout << bfs_order[i]<<' ';
	cout << endl;




}





int main()
{
	int idx;
	cin >> N >> M>>idx;
	adj = vector<vector<int>>(N + 1, vector<int>());
	
	//adj초기화
	for (int i = 1; i <= M; i++) {
		int temp1, temp2;
		cin >> temp1>> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	
	for (int i = 1; i <= N; i++) {
		//오름차순으로 정렬 
		sort(adj[i].begin(), adj[i].end());

	}
	

	findAns(idx);
	
	
	return 0;
}