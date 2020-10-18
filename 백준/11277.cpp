#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

//���� �׷�������, SCC��� ������ ���α׷� �ۼ�.
//SCC��, ������ �ִ� �κ����� (u-> v,  v->u�� ��� �����Ѵ�.)

int N,M;
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