#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, int>> house;
vector<pair<int, int>> store;

int calDist(const vector<pair<int,int>>& curStore) {
	int sumOfDist = 0;

	for (int i = 0; i < house.size(); i++) {
		int dist = 987654321;
		for (int j = 0; j < curStore.size(); j++) {
			int temp = abs(curStore[j].first - house[i].first) + abs(curStore[j].second - house[i].second);
			if (dist > temp)
				dist = temp;
		}
		sumOfDist += dist;
	}

	return sumOfDist;

}




int findAns(vector<pair<int,int>>& curStore,int count = 0) {

	int minV =987654321;
	//basecase
	if (count == store.size()) {
		if (curStore.size() == M) { //정답
			/*
			for (int i = 0; i < curStore.size(); i++) {
				cout << curStore[i].first << ' ' << curStore[i].second << endl;
			}
			cout << endl << endl;
			*/
			return calDist(curStore);
		}
		else { //오답
			return 987654321;
		}

	}

	minV = min(minV, findAns(curStore, count + 1));
	curStore.push_back({ store[count].first, store[count].second });
	minV = min(minV, findAns(curStore, count + 1));
	curStore.pop_back();

	return minV;

}




int main() {
	cin >> N >> M;
	vector<vector<int>> board = vector<vector<int>>(N, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			board[i].push_back(temp);

			if (temp == 1)
				house.push_back({ i,j });
			else if (temp == 2)
				store.push_back({ i,j });

		}

	}

	vector<pair<int, int>> temp = vector<pair<int,int>>();
	cout << findAns(temp)<<endl;



}


