//백준 2152번
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int sccCounter, nodeCounter;
vector<int> discovered;
vector<int> sccId;
vector<vector<int>> adj;
stack<int> st;

int scc(int here) {
	int ret = discovered[here] = nodeCounter++;

	st.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];


		//첫방문
		if (discovered[there] == -1) {
			ret = min(ret, scc(there));
		}
		else if (sccId[there] == -1) {
			ret = min(ret, discovered[there]);
		}
	}

	//모두 종료 후 -->here보다 더 위로 갈 수 없는 경우
	if (ret == discovered[here]) {
		while (true) {
			int dst = st.top();
			st.pop();

			sccId[dst] = sccCounter;

			if (dst == here)
				break;
		}
		sccCounter++;
	}

	return ret;
}

vector<int> sccNum; //각 scc의 노드갯수
vector<vector<bool>> sccMat;
vector<vector<bool>> makeSccMat() {
	vector<vector<bool >> sccAdj = vector<vector<bool>>(sccCounter, vector<bool>(sccCounter,false));
	
	sccNum = vector<int>(sccCounter, 0);
	for (int i = 0; i < sccId.size(); i++) {
		//scc numbering이 된 경우만 추가.
		if(sccId[i] != -1)
			sccNum[sccId[i]]++;
	}


	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int srcScc = sccId[i];
			int dstScc = sccId[adj[i][j]];
			//자기자신은 기입안한다.
			//scc numbering이 된 경우에만 행렬에추가.
			if (srcScc != -1 && dstScc != -1 && srcScc != dstScc)
				sccAdj[srcScc][dstScc] = true;

		}
	}
	return sccAdj;
}

//sccMat 사용
int topologicalSort(int S , int T ) {
	int size = sccMat.size();
	vector<int> max_num = vector<int>(size, -1);
	vector<int> indegree = vector<int>(size, 0);
	queue<int> Q;

	//indegree, outdegree채운다.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sccMat[j][i] == true)
				indegree[i]++;
		}
	}

	//indegree 0인 값들 채워준다.
	for (int i = 0; i < size; i++) {
		if (indegree[i] == 0) {
			max_num[i] = sccNum[i];

			Q.push(i);
		}
	}
	int here = -1;
	while (!Q.empty() && here != sccId[T]) {
		here = Q.front();
		Q.pop();

		for (int i = 0; i < size; i++) {
			if (sccMat[here][i] ==true) {
				sccMat[here][i] = false;
				indegree[i]--;
				//계속 비교하면서 최댓값할당. <다시해보기>
				max_num[i] = max(max_num[i], max_num[here] +sccNum[i]);
				//cout << "asdf " << sccNum[here] <<' '<<sccNum[i]<<' '<<max_num[i] << endl;
				if (indegree[i] == 0)
					Q.push(i);
			}
		}
	}



	return max_num[here];


}

void findAns(int S, int T) {
	discovered = vector<int>(sccCounter, -1);
	sccMat = makeSccMat();
	cout << topologicalSort(S,T) << endl;

}

void tarzanScc(int S, int T) {
	sccCounter = nodeCounter = 0;
	discovered = sccId = vector<int>(adj.size(), -1);
	scc(S); //scc를 한 번 수행했을 때, T에 sccId numbering이 된다면, 일단 path가존재.

	if (sccId[T] == -1) {//numbering이 되지않은경우
		cout << "0" << endl;
		return;
	}

	//numbering이 된경우 -> path가 무조건 존재한다.
	findAns(S, T);




	return;
}





int main() {

	int N, M, S, T;

	cin >> N >> M >> S >> T;
	adj = vector<vector<int>>(N, vector<int>());


	for (int i = 0; i < M; i++) {
		int src, dst;
		cin >> src >> dst;
		adj[src-1].push_back(dst-1);

	}

	tarzanScc(S-1,T-1);

	return 0;
}

