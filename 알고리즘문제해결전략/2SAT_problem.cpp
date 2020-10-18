#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;

vector< vector<int>> adj;

vector<int> discovered;
vector<int> sccId;
stack<int> st;
int sccCounter, vertexCounter;


int scc(int here) {

	
	int ret = discovered[here] = vertexCounter ++;

	st.push(here);

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}

	if (ret == discovered[here]) {

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

vector<int> tarjanScc() {
	sccId = discovered = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 1;

	for (int i = 0; i < adj.size(); i++) {
		if (discovered[i] == -1)
			scc(i);
	}

	return sccId;

}

bool findAns() {

	tarjanScc();











	for (int i = 0; i < sccId.size(); i += 2) {
		if (sccId[i] == sccId[i + 1]) 
			return false;
	}

	return true;


}











int main()
{
	cin >> N >> M;

	adj = vector<vector<int>>(2 * N, vector<int>());

	for (int i = 0; i <M ; i++) {
		int src, dst;
		cin >> src>> dst;
		if (src < 0) 
			src = abs(src) * 2 -1;
		else
			src = src * 2-2;

		if (dst < 0)
			dst = abs(dst) * 2 -1;
		else
			dst = dst * 2-2;


		if (src % 2 == 0)
			adj[src + 1].push_back(dst);
		else
			adj[src-1].push_back(dst);

		if (dst % 2 == 0)
			adj[dst + 1].push_back(src);
		else
			adj[dst-1].push_back(src);

	}

	if (findAns())
		cout << 1 << endl;
	else
		cout << 0 << endl;
	
	
	




	return 0;
}