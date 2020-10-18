//해밀토니안 경로 
//시간초과뜬다... ㅠㅠ (각 정점을 스트링으로 두고 한 경우에)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> str;

//정렬된 str을 기준으로
//이전 단어의 끝문자가 다음 단어의 첫문자와 같은 경우에 1
//자신의 첫과 끝이 같은경우 (ex) dad)같은 건 추가하지 않음(각 노드를 한번 순회하므로 필요x)
void make_graph(vector<vector<int>>& adj, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if (str[i].back() == str[j].front() && i != j) {
				adj[i][j] = 1;
			}
		}
	}
}


vector<bool> visit(100,false);
vector<int> vertex;
int is_all_find(int start, int num, int N, vector<vector<int>>& adj)
{
	visit[start] = true;
	if (num == N) {
		vertex.push_back(start);
		visit[start] = false;
		return 1;
	}
	for (int i = 0; i < N; i++) {
		if (adj[start][i] == 1 && visit[i] == false) {
			if (is_all_find(i, num + 1, N, adj)==1) {
				vertex.push_back(start);
				visit[start] = false;
				return 1;
			}
		}

	}
	visit[start] = false;
	return -1;
}

bool find_all(int N, vector<vector<int>>& adj)
{
	for (int i = 0; i < N; i++) {
		if (is_all_find(i, 1, N, adj) == 1) {
			reverse(vertex.begin(), vertex.end());
			return true;
		}
	}
	
	return false;
}






int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		str.clear();
		vertex.clear();
	
		int N; //총 단어의 수
		cin >> N;
		vector< vector<int>> adj(N, vector<int>(N,0)); //인접행렬(정렬된str을 기준으로채운다.)
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			str.push_back(temp);
		
		}

		sort(str.begin(), str.end()); //사전 순으로 정렬

		make_graph(adj, N);

		if (find_all(N, adj)) {
			for (int i = 0; i < N-1; i++)
				cout << str[vertex[i]] << ' ';
			cout << str[vertex[N - 1]] << endl;

		}
		else
		{
			cout << "IMPOSSIBLE" << endl;
		}

		
	}



	return 0;
}




