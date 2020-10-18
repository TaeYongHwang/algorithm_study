//��� ������ ��츦 �� �����ؾ� �ƴ� ����.
//cctv�� ��ġ ��ġ��, cctv�� ���̴� ��ġ, �Ⱥ��̴� ��ġ�� �����ϴ� �� ���� ��.
//�ܿ� �����س� ���� : ��Ʈ�� ����, ��Ʈ�� �ڽĵ��� ��� cctv�� "���̴� ��ġ�� ����"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int G, H;// G : ������ ��, H : ���� ��

vector<vector <int>> adj;
vector<int> con_count;

//dfs�̿��� �Լ� �����
//������忡 ���� �� ����(basecase)
//�ڽĵ� �� ī�޶� �������� �ʴ� ��尡 �����Ѵٸ�, �ش� ��忡 ī�޶� �ް�
//����
//�� ī�޶� �� ��ȯ.

vector<bool> cctv;
vector<bool> visited;


int dfs(const int idx)
{
	int cctv_count = 0;
	bool is_leaf_node = true;
	vector<int> children;
	visited[idx] = true;
	
	//basecase 1 :���� ��� - > ������ 1���� ��ġ�ؾߵȴ�.
	if (con_count[idx] == 0) {
		cctv[idx] = true;
		return 1;
	}
	
	
	//DFS search 
	for (int i = 0; i < adj[idx].size(); i++) {
		//�湮���� ���� ��쿡�� �� �� �ֵ���.
		if (visited[adj[idx][i]] == false) {
			is_leaf_node = false; //�� �� ��尡 ���������Ƿ�.
			children.push_back(adj[idx][i]); //�ڽ� ���� �� �� �ִ�.
	
			cctv_count +=dfs(adj[idx][i]); //�ش� �ڽı��� ��ġ�� ��� cctv������ ������
			
		}
	}

	//basecase 2 : ��������� ��� -> ��ġ�� ���ϰ� �����Ų��.
	if (is_leaf_node == true) {
		return 0;
	}


	//�ڽ� �� �ϳ��� cctv�� �簢���뿡 �����ϴ� ���.
	bool do_cctv = false;
	for (int i = 0; i < children.size(); i++) {
		if (!cctv[children[i]]) { //�ش� �ڽ��� cctv�� �簢���뿡����
			do_cctv = true;
			break;
		}
	}

	//�ڽ� �� �ϳ��� cctv�� �簢���뿡 �ִ� ���.
	//�ڽſ��� cctv��ġ.
	if (do_cctv) {

		cctv[idx] = true; //���� ��ġ�� cctv��ġ

		//���� ��ġ�� ����� ��� vertex�� cctv�� �ݰ� ���� ����. 
		for (int i = 0; i < adj[idx].size(); i++) {
			cctv[adj[idx][i]] = true;
		}

		return cctv_count + 1;
	}


	//��� �ڽ��� cctv�� �ݰ� ���� �����ϴ� ��� 
	return cctv_count;

}


int dfs_all(){


	visited = vector<bool>(G, false);
	cctv = vector<bool>(G, false);
	int count = 0;
	for (int i = 0; i < G; i++) {
		if(visited[i] == false)
			count += dfs(i);

		//���� �ش� ���� ��Ʈ�̰�, �ڽĵ��� ��� cctv�� ���̴� ��쿡
		//���� �߰��� ����ߵ�(dfs�� �������̽�)
		if (!cctv[i])
			count++;
		

	}
	
	return count;

}




int main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> G >> H;
		adj = vector<vector<int>>(G, vector<int>(0));
		con_count = vector<int>(G,0);

		//���� ���� ����Ʈ ��ä���
		for (int i = 0; i < H; i++) {
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
			con_count[a]++;
			con_count[b]++;

		}

		cout << dfs_all() << endl;






	}
	return 0;
}