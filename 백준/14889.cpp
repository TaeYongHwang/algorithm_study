#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> ability;

//�־��� ���Ϳ��� ������ ���� ���
int sumOfAbility(vector<int>& v) {

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			int idx1 = v[i];
			int idx2 = v[j];
			sum += ability[idx1][idx2];
		}
	}
	return sum;

}



int findAns(vector<int>& sTeam, vector<int>& lTeam, int num =0) {
	int minV = 987654321;

	//basecase :
	//1. ��� ����� ���� ������ ���
	if (num == N) {
		//���ݾ� ��Ȯ�� ��е� ���
		if (sTeam.size() == N / 2 && lTeam.size() == N / 2) {
			return abs(sumOfAbility(sTeam) - sumOfAbility(lTeam));

		}
		//����� ��Ȯ�� �ȵ� ���
		else {
			return 987654321;
		}

	}

	//1. �ش� ����� start team�� �� ���
	sTeam.push_back(num);
	minV = min(minV, findAns(sTeam, lTeam, num + 1));
	sTeam.pop_back();

	//2. �ش� ����� link team�� �� ���
	lTeam.push_back(num);
	minV = min(minV, findAns(sTeam, lTeam, num + 1));
	lTeam.pop_back();


	return minV;

}



int main() {
	cin >> N;
	ability = vector<vector<int>>(N, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			ability[i].push_back(temp);
		}
	}

	vector<int> sTeam;
	vector<int> lTeam;

	cout << findAns(sTeam, lTeam)<<endl;




	return 0;
}