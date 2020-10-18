#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

//방향 그래프에서, SCC들로 나누는 프로그램 작성.
//SCC란, 정점의 최대 부분집합 (u-> v,  v->u가 모두 존재한다.)

int N,M;
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

int negation_var(int var) {
	if (var % 2 == 1) {
		return var + 1;
	}
	else
		return var - 1;

}


int main()
{
	cin >> N >> M;
	adj = vector<vector<int> >(2*N + 1, vector<int>(0));

	for (int i = 0; i < M; i++) {
		int var1, var2;
		cin >> var1 >> var2;

		//case 1 : change nodeNum
		if (var1 > 0) {
			var1 = 2 * var1 - 1;
		} else {
			var1 = abs(var1) * 2 ;
		}
		
		if (var2 > 0) {
			var2 = 2 * var2 - 1;
		}
		else {
			var2 = abs(var2) * 2;
		}

		adj[negation_var(var1)].push_back(var2);
		adj[negation_var(var2)].push_back(var1);

	}

	tarjanSCC();

	bool tf = true;
	for (int i = 1; i < 2 * N; i += 2) {
		if (sccId[i] == sccId[i + 1]) {
			cout << 0 << endl;
			tf = false;
			break;
			
		}
	}

	if (tf) {
		cout << 1 << endl;
	}



	return 0;
}