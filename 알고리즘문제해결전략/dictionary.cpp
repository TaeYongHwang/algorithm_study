//������ �������� ����
//����� DAG�˻�� ���������� ��������
//->�ð��ʰ�  (print()�� �̿��� ���)
//         --> ���������� ���ϰ� �ҷ��� �ϴ� ��쿡 �ð��ʰ�
//���� ���� �� �ſ� �γ�

#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

#define MAKEIDX 97 //97��ŭ ����� 0�ε����� �´�.(�ƽ�Ű�ڵ�)

int N; //�ܾ��� �� (����������, ���ĺ� �ҹ��ڸ�)
vector<string> words; //�ܾ���� ������� �����س��´�.

bool adjmat[26][26]; //�����������

//�̹� ����� ���(�̹� ����� ������ �������� �����Ϸ��ϴ� ��쿡 ����̻���)
//adjmat[row][col]�� true�� ������ش�.
bool connected(int row, int col) {


	if (adjmat[col][row] == true) //�������� �̹� ������ִ� ���
		return false;
	else
		adjmat[row][col] = true;
	return true;
}

int create_mat(int str_idx = 0,int start= 0 , int end =N) //[)���
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
	
	//basecase  ; ������ 1������ ���
	if (end - start == 1)
		return 0;


	int num = 1; //�⺻������ 1���̹Ƿ�
	//���� �ε����� ������ ������ ������ �ݺ�
	
	for (int i = start; i < end - 1; i++) {
		//�ش� �ε������� NULL�ΰ�� ->�׳ɳѾ
		if (words[i].size() == str_idx)
			continue;

		//�����ڸ��� ���ĺ����� ���� ���
		if (words[i][str_idx] == words[i + 1][str_idx]) {
			num++;
			continue;	
		}
		else //�ٸ� ���
		{
			//�ٸ� �ΰ��� ���� (������� �ε����� ��������Ѵ�)
			if (!connected(words[i][str_idx] - MAKEIDX, words[i + 1][str_idx] - MAKEIDX)) {
				cout << "INVALID HYPOTHESIS" << endl;
				return -1;
			}
			//�տ� ���� �κе��� ���ȣ��(srt_idx�� 1��ŭ������)
			if (create_mat(str_idx + 1, i + 1 - num, i + 1) == -1)
				return -1;
			//������ �ٽ� 0���� ���� 
			num = 1;

		}

	}

	//���������� ���Ƽ� for���� �ɸ��� �ʴ� ���
	if (num > 1) {
		if (create_mat(str_idx + 1, end - num, end) == -1)
			return -1;

	}
	return 0;
	
}

//���Ἲ�� ������ �׳� ���
//���Ἲ�� ������ �ش粨�� ����Ȱ� �ִ��� Ȯ���ؼ� ������ ����� ���鼭���
bool visit[26]; //�̹� ����ߴ��� Ȯ��

//idx�� ����Ű�� ������ �����ϴ���
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
	//basecase : idx�� 26�������� ��.or �̹� �湮�� ���
	if (idx == 26 || visit[idx] == true)
		return 0;

	visit[idx] = true;
	//�ڽ��� ����Ű�� ������ ���� 
	if(is_edge(idx) == true){
		int i;
		//�ڽ��� ����Ű�� ��������� ���ȣ��
		for (i = 0; i < 26; i++)
			if (adjmat[i][idx] == true)
				print_all(i);
	}
	cout << (char)(idx + MAKEIDX);
	//�ڽ��� ����Ű�� ������ �����ϴ� ���
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
		//������ �ִ°��
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
		
		//������� �ʱ�ȭ
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