#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N;

//방문한 적이 없고, 리프노드에 도달할 때까지.

int tree_exit(vector<bool>& visit, vector<vector<int>> & adj, int idx = 1, int level = 0)
{


	int sum = 0;
	//들어온 인덱스 체크
	if (visit[idx] == true)
		return 0;



	visit[idx] = true;

	//연결된 모든 경우에 (방문x)대해 재귀
	for (int i = 0; i < adj[idx].size(); i++) {
		if (visit[adj[idx][i]] == false)
			sum += tree_exit(visit, adj, adj[idx][i], level + 1);
	}


	if (sum == 0) { //리프노드인경우

		return level;
	}

	return sum;
}





int main()
{
	cin >> N;
	vector< vector<int> > adj(N + 1, vector<int>());
	vector<bool> visit(N + 1, false);
	while (--N) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);


	}


	if (tree_exit(visit, adj) % 2 == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;




	return 0;
}