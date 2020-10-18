//모든 예외의 경우를 잘 생각해야 됐던 문제.
//cctv의 설치 위치와, cctv에 보이는 위치, 안보이는 위치로 생각하는 게 편한 듯.
//겨우 생각해낸 예외 : 루트만 남고, 루트의 자식들은 모두 cctv에 "보이는 위치에 존재"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int G, H;// G : 갤러리 수, H : 간선 수

vector<vector <int>> adj;
vector<int> con_count;

//dfs이용한 함수 만들기
//리프노드에 도달 시 종료(basecase)
//자식들 중 카메라에 비춰지지 않는 노드가 존재한다면, 해당 노드에 카메라를 달고
//리턴
//총 카메라 수 반환.

vector<bool> cctv;
vector<bool> visited;


int dfs(const int idx)
{
	int cctv_count = 0;
	bool is_leaf_node = true;
	vector<int> children;
	visited[idx] = true;
	
	//basecase 1 :고립된 경우 - > 무조건 1개는 설치해야된다.
	if (con_count[idx] == 0) {
		cctv[idx] = true;
		return 1;
	}
	
	
	//DFS search 
	for (int i = 0; i < adj[idx].size(); i++) {
		//방문하지 않은 경우에만 들어갈 수 있도록.
		if (visited[adj[idx][i]] == false) {
			is_leaf_node = false; //더 들어갈 노드가 남아있으므로.
			children.push_back(adj[idx][i]); //자식 노드로 볼 수 있다.
	
			cctv_count +=dfs(adj[idx][i]); //해당 자식까지 설치한 모든 cctv갯수를 더해줌
			
		}
	}

	//basecase 2 : 리프노드인 경우 -> 설치를 안하고 종료시킨다.
	if (is_leaf_node == true) {
		return 0;
	}


	//자식 중 하나라도 cctv의 사각지대에 존재하는 경우.
	bool do_cctv = false;
	for (int i = 0; i < children.size(); i++) {
		if (!cctv[children[i]]) { //해당 자식이 cctv의 사각지대에존재
			do_cctv = true;
			break;
		}
	}

	//자식 중 하나라도 cctv의 사각지대에 있는 경우.
	//자신에게 cctv설치.
	if (do_cctv) {

		cctv[idx] = true; //현재 위치에 cctv설치

		//현재 위치에 연결된 모든 vertex가 cctv의 반경 내에 존재. 
		for (int i = 0; i < adj[idx].size(); i++) {
			cctv[adj[idx][i]] = true;
		}

		return cctv_count + 1;
	}


	//모든 자식이 cctv의 반경 내에 존재하는 경우 
	return cctv_count;

}


int dfs_all(){


	visited = vector<bool>(G, false);
	cctv = vector<bool>(G, false);
	int count = 0;
	for (int i = 0; i < G; i++) {
		if(visited[i] == false)
			count += dfs(i);

		//만약 해당 점이 루트이고, 자식들이 모두 cctv에 보이는 경우에
		//따로 추가를 해줘야됨(dfs의 예외케이스)
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

		//무향 인접 리스트 값채우기
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