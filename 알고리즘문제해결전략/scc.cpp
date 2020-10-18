#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//방향 그래프에서, SCC들로 나누는 프로그램 작성.
//SCC란, 정점의 최대 부분집합 (u-> v,  v->u가 모두 존재한다.)

int V, E;
//정점은 1번부터 V번까지 매겨진다.

vector< vector<int>> adj;

vector<int> sccId;
vector<int> discovered;
stack <int> st;
int sccCounter, vertexCounter;

int scc(int here) {
	//cout << "here :" << here << endl;
	//ret : here를 root로하는 subtree에서 올라갈 수 있는 가장 높은 정점의 번호
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		
		//(here, there)이 트리 간선
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		//there가 무시해야 하는 교차간선이 아니라면
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}

	//here에서 부모로 올라가는 간성을 끊어야 할지 확인
	if (ret == discovered[here]) {
		//here를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다.
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here)
				break;
		}
		++sccCounter;
	}
	return ret;

}

vector<int> tarjanSCC() {
	sccId = discovered = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 1;

	for (int i = 1; i < adj.size(); i++) {
		if (discovered[i] == -1)
			scc(i);
	}
	return sccId;
}







void print_ans() {
	cout << sccCounter - 1<<endl;

	vector<vector<int>> sccVec = vector < vector<int>>(sccCounter - 1, vector<int>(0));

	for (int i = 1; i < sccId.size(); i++) {
		sccVec[sccId[i] -1].push_back(i);
	}
	
	//각 vector 내부를 정렬시킴
	for (int i = 0; i < sccVec.size(); i++) {
		sort(sccVec[i].begin(), sccVec[i].end());
	}
	//각 vector의 맨 앞 값을 비교해 전체 벡터정렬.
	
	sort(sccVec.begin(), sccVec.end());

	for (int i = 0; i < sccVec.size(); i++) {
		for (int j = 0; j < sccVec[i].size(); j++) {
			cout << sccVec[i][j] << ' ';
		}
		cout << "-1" << endl;
	}

	




}






int main()
{
	cin >> V >> E;
	adj = vector<vector<int> >(V+1, vector<int>(0));
	
	for (int i = 0; i < E; i++) {
		int src, dst;
		cin >> src >> dst;
		adj[src].push_back(dst);
	}

	tarjanSCC();
	

	print_ans();
	



	return 0;
}