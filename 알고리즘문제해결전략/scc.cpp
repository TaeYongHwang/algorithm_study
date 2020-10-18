#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//���� �׷�������, SCC��� ������ ���α׷� �ۼ�.
//SCC��, ������ �ִ� �κ����� (u-> v,  v->u�� ��� �����Ѵ�.)

int V, E;
//������ 1������ V������ �Ű�����.

vector< vector<int>> adj;

vector<int> sccId;
vector<int> discovered;
stack <int> st;
int sccCounter, vertexCounter;

int scc(int here) {
	//cout << "here :" << here << endl;
	//ret : here�� root���ϴ� subtree���� �ö� �� �ִ� ���� ���� ������ ��ȣ
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		
		//(here, there)�� Ʈ�� ����
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		//there�� �����ؾ� �ϴ� ���������� �ƴ϶��
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}

	//here���� �θ�� �ö󰡴� ������ ����� ���� Ȯ��
	if (ret == discovered[here]) {
		//here�� ��Ʈ�� �ϴ� ����Ʈ���� ���� �ִ� �������� ���� �ϳ��� ������Ʈ�� ���´�.
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
	
	//�� vector ���θ� ���Ľ�Ŵ
	for (int i = 0; i < sccVec.size(); i++) {
		sort(sccVec[i].begin(), sccVec[i].end());
	}
	//�� vector�� �� �� ���� ���� ��ü ��������.
	
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