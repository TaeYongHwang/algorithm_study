//정교한 위상정렬 구현
//현재는 DAG검사와 위상정렬이 따로존재
//->시간초과  (print()를 이용한 경우)
//         --> 위상정렬을 안하고 할려고 하는 경우에 시간초과
//위상 정렬 시 매우 널널

#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

#define MAKEIDX 97 //97만큼 빼줘야 0인덱스에 맞다.(아스키코드)

int N; //단어의 수 (사전순서로, 알파벳 소문자만)
vector<string> words; //단어들을 순서대로 저장해놓는다.

bool adjmat[26][26]; //방향인접행령

//이미 연결된 경우(이미 연결된 순서의 역순으로 연결하려하는 경우에 모순이생김)
//adjmat[row][col]을 true로 만들어준다.
bool connected(int row, int col) {


	if (adjmat[col][row] == true) //역방향이 이미 연결되있는 경우
		return false;
	else
		adjmat[row][col] = true;
	return true;
}

int create_mat(int str_idx = 0,int start= 0 , int end =N) //[)모양
{
	/*
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		for(int k = 0 ; k<len; k++)
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adjmat[a][b] = true;
				break;
			}
	}
	return 0;
	*/
	
	//basecase  ; 갯수가 1개뿐인 경우
	if (end - start == 1)
		return 0;


	int num = 1; //기본갯수가 1개이므로
	//시작 인덱스가 끝까지 도달할 때까지 반복
	
	for (int i = start; i < end - 1; i++) {
		//해당 인덱스값이 NULL인경우 ->그냥넘어감
		if (words[i].size() == str_idx)
			continue;

		//같은자리의 알파벳값이 같은 경우
		if (words[i][str_idx] == words[i + 1][str_idx]) {
			num++;
			continue;	
		}
		else //다른 경우
		{
			//다른 두개를 연결 (인접행렬 인덱싱을 맞춰줘야한다)
			if (!connected(words[i][str_idx] - MAKEIDX, words[i + 1][str_idx] - MAKEIDX)) {
				cout << "INVALID HYPOTHESIS" << endl;
				return -1;
			}
			//앞에 같은 부분들을 재귀호출(srt_idx를 1만큼높여서)
			if (create_mat(str_idx + 1, i + 1 - num, i + 1) == -1)
				return -1;
			//갯수를 다시 0으로 만듦 
			num = 1;

		}

	}

	//마지막까지 같아서 for문에 걸리지 않는 경우
	if (num > 1) {
		if (create_mat(str_idx + 1, end - num, end) == -1)
			return -1;

	}
	return 0;
	
}

//연결성이 없으면 그냥 출력
//연결성이 있으면 해당꺼에 연결된게 있는지 확인해서 없으면 출력후 들어가면서출력
bool visit[26]; //이미 출력했는지 확인

//idx를 가리키는 간선이 존재하는지
bool is_edge(int idx)
{
	for (int i = 0; i < 26; i++)
		if (adjmat[i][idx] == true)
			return true;

	return false;
	
}
bool is_direct(int idx)
{
	for (int i = 0; i < 26; i++)
		if (adjmat[idx][i] == true)
			return true;
	return false;

}


int print_all(int idx = 0) 
{	
	//basecase : idx가 26에도달할 시.or 이미 방문한 경우
	if (idx == 26 || visit[idx] == true)
		return 0;

	visit[idx] = true;
	//자신을 가리키는 간선이 존재 
	if(is_edge(idx) == true){
		int i;
		//자신을 가리키는 노드쪽으로 재귀호출
		for (i = 0; i < 26; i++)
			if (adjmat[i][idx] == true)
				print_all(i);
	}
	cout << (char)(idx + MAKEIDX);
	//자신이 가리키는 간선이 존재하는 경우
	if (is_direct(idx) == true) {
		for (int i = 0; i < 26; i++) {
			if (adjmat[idx][i] == true )
				print_all(i);
		}
	}
	return 0;
}

bool cycle[26] = { false, };
bool is_cycle(int idx = 0)
{
	int i;

	if (cycle[idx] == true)
		return true;

	cycle[idx] = true;
	for (i = 0; i < 26; i++) {
		//간선이 있는경우
		if (adjmat[idx][i] == true) {
			if (is_cycle(i) == true)
				return true;
		}
	}

	cycle[idx] = false;


	return false;
}
bool cycle_exist()
{
	for (int i = 0; i < 26; i++) {
		if (is_cycle(i))
			return true;
	}

	return false;


}



void print()
{
	if(cycle_exist()) {
		cout << "INVALID HYPOTHESIS";
		return;
	}

	int i= 0;
	while (i != 26)
	{
		for (i = 0; i < 26; i++) {
			if (visit[i] == false) {
				if (print_all(i) == -1)
					return;
				break;
			}
		}

	}

	return;
}



vector<int> seen, order;
void dfs(int here)
{
	seen[here] = 1;
	for (int i = 0; i < 26; i++)
		if (adjmat[here][i] && !seen[i])
			dfs(i);
	order.push_back(here);
}

vector<int> topologicalSort() {
	int n = 26;
	seen = vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; i++)
		if (!seen[i])
			dfs(i);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (adjmat[order[j]][order[i]])
				return vector<int>();
	return order;



}






int main()
{
	int C;
	cin >> C;
	
	while (C--)
	{
		words.clear();
		cin >> N;
		
		//인접행렬 초기화
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				adjmat[i][j] = false;
		for (int i = 0; i < 26; i++) {
			visit[i] = false;
			cycle[i] = false;
		}


		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			words.push_back(temp);
		}

		//cout << create_mat() << endl;
		
		if (create_mat() == 0) {
			if (topologicalSort().empty())
				cout << "INVALID HYPOTHESIS";
			else
				for (int i = 0; i < order.size(); i++)
					cout << (char)(order[i]+MAKEIDX);			
			cout << endl;
		}

	}



	return 0;
}