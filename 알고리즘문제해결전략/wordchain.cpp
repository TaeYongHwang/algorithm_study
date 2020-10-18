//오일러패스
//각 알파벳을 정점으로 두고, 스트링들을 간선으로 표현
//책거의참조.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAKEIDX 97

int N;
int arr[26][26]; //각 알파벳
vector<string> graph[26][26];
vector<int> indegree, outdegree;

void make_graph(vector<string> & str) {

	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++) {
			graph[i][j].clear();
			arr[i][j] = 0;
		}
	}

	indegree = outdegree = vector<int>(26, 0);


	for (int i = 0; i < N; i++) {
		int a = str[i].front() - MAKEIDX;
		int b = str[i].back() - MAKEIDX;

		arr[a][b]++;
		graph[a][b].push_back(str[i]);
		outdegree[a]++;
		indegree[b]++;

	}
}

void getEulerCircuit(int here, vector<int>& circuit) {
	for (int i = 0; i < 26; i++) {
		while (arr[here][i] > 0) {
			arr[here][i] --;
			getEulerCircuit(i, circuit);
		}
	}
	circuit.push_back(here);

}

vector<int> getEulerTrailOrCircuit() {
	vector<int> circuit;
	//find euler trail
	for (int i = 0; i < 26; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
				return circuit;
		}
	}

	return circuit;//빈배열
}

bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		
		if (delta < -1 || 1 < delta)
			return false;
		if (delta == 1)
			plus1++;
		if (delta == -1)
			minus1++;
	}

	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(vector<string>& words) {
	make_graph(words);
	
	if (!checkEuler())
		return "IMPOSSIBLE";

	vector<int> circuit = getEulerTrailOrCircuit();
	

	if (circuit.size() != words.size() + 1)
		return "IMPOSSIBLE";

	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size())
			ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;

}






int main()
{
	int C;
	cin >> C;
	while (C--) {



		cin >> N;
		vector<string> str;
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			str.push_back(temp);
		}

		string ans = solve(str);

		cout << ans << endl;



	}








	return 0;
}