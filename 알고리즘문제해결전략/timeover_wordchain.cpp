//�ع���Ͼ� ��� 
//�ð��ʰ����... �Ф� (�� ������ ��Ʈ������ �ΰ� �� ��쿡)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> str;

//���ĵ� str�� ��������
//���� �ܾ��� �����ڰ� ���� �ܾ��� ù���ڿ� ���� ��쿡 1
//�ڽ��� ù�� ���� ������� (ex) dad)���� �� �߰����� ����(�� ��带 �ѹ� ��ȸ�ϹǷ� �ʿ�x)
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
	
		int N; //�� �ܾ��� ��
		cin >> N;
		vector< vector<int>> adj(N, vector<int>(N,0)); //�������(���ĵ�str�� ��������ä���.)
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			str.push_back(temp);
		
		}

		sort(str.begin(), str.end()); //���� ������ ����

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




