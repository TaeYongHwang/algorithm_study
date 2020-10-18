//BFS�Լ� ���� �ð� �ʰ�
//->�� ���ڵ��� ���� ������� 1~N�� ���ڷ� ġȯ
//->���� ���ĵ� ���¿��� �ش� ���·� ���� �ּҰŸ� ��, No weight ���� �׷���������
//�ּ��н�ã�� ������ ������ ������

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N;

int bfs(const vector<int>& origin) {
	const int size = origin.size();
	vector<int> ans = origin;
	sort(ans.begin(), ans.end());
	
	queue<vector<int>> Q;
	map<vector<int>, int> distance;
	distance[origin] = 0;
	Q.push(origin);
	while (!Q.empty()) {
		vector<int> here = Q.front();
		Q.pop();

		if (here == ans)
			return distance[here];

		int cost = distance[here];

		for (int i = 0; i < N; i++) {
			for (int j = i + 2; j <= N; j++) {
				reverse(here.begin() + i, here.begin() +j );
				if (distance.count(here) == 0) {
					distance[here] = cost + 1;
					Q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);

			}
		}


	}
	return -1;
}


//���ĵ� ���¿��� �ٸ� ��������� �Ÿ��� map������
map<vector<int>, int> preCalc()
{
	map<vector<int>, int> dist;
	vector<int> sorted;
	queue<vector<int>> Q;

	for (int i = 1; i <= 8; i++) { //i�� vector�� size
		sorted.push_back(i);
		Q.push(sorted);
		dist[sorted] = 0;
		while (!Q.empty()) {
			vector<int> here = Q.front();
			Q.pop();			
			int cost = dist[here];
			//��� ��쿡���� bfs
			for (int j = 0; j < i; j++) {
				for (int k = j + 2; k <= i; k++) {
					reverse(here.begin() + j, here.begin() + k);
					if (dist.count(here) == 0) {
						dist[here] = cost + 1;
						Q.push(here);
					}
					reverse(here.begin() + j, here.begin() + k);
				}
			}
		}
	}
	return dist;
}

//origin���͸� ũ�Ⱚ (1~N)���κ���
vector<int> convert(vector<int> origin)
{
	vector<int> converted = vector<int>(N,0);
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (origin[i] > origin[j])
				count++;
		}
		converted[i] = count+1;
	
	}
	/*
	for (int i = 0; i < N; i++)
		cout << converted[i] << ' ';
	cout << endl;
	*/
	return converted;

}








int main()
{
	int C;
	cin >> C;
	map<vector<int>, int> ansMap = preCalc();
	while (C--) {
		cin >> N;
		vector<int> origin;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			origin.push_back(temp);
		}
	

		cout << ansMap[convert(origin)] << endl;




	}
	return 0;
}