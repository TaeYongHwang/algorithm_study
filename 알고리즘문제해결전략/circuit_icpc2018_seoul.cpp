#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int y;
list<pair<int, int>> rangeList;
vector< pair<int, int>> rangeVec; //시작값을 기준으로 오름차순으로 정렬
vector<int> startVec; //시작값을 내림차순으로 정렬할것.
vector<int> endVec;   //끝값을 내림차순으로 정렬할것.

int findMax() {
	int maxValue = -1, curValue =0, open = -1, close = -1;
	int yValue;
	while (!startVec.empty()) {

		//꺼내야되는 값에 대해 -1로 초기화시켜둔다.(while의 마지막에)
		if (open == -1) {
			open = startVec.back();
			startVec.pop_back();

		}
		if (close == -1) {
			close = endVec.back();
			endVec.pop_back();
		}

		//비교문
		if (open <= close) { //닫히기전에 하나가 더 열린경우
			curValue++;
			open = -1;
			continue;
		} else { //열리기전에 하나가 더 닫힌경우
			if (maxValue<curValue ) {
				maxValue = curValue;
				yValue = close;
			}

			curValue--;
			close = -1;
			continue;
		}
	}

	if (!endVec.empty() && maxValue < curValue) {
		maxValue = curValue;
		yValue = close;
	}

	y = yValue;
	return maxValue;
}

//y값사용해서, 그곳에있는 값들을 모두 삭제시킨다.
//rangeVec.
void reMake() {
	const int criteria = y;

	list<pair<int, int>>::iterator iter = rangeList.begin();
	while (iter != rangeList.end() ) {
		if (iter->first <= criteria && iter->second >= criteria) {
			iter = rangeList.erase(iter);
			if (iter == rangeList.end())
				break;
		}
		else {
			if (iter == rangeList.end())
				break;
			iter++;
		}
	}
	startVec.clear();
	endVec.clear();
	rangeVec.clear();

	iter = rangeList.begin();
	while (iter != rangeList.end()) {
		rangeVec.push_back(*iter++);
	}


	for (int i = 0; i < rangeVec.size(); i++) {
		startVec.push_back(rangeVec[i].first);
		endVec.push_back(rangeVec[i].second);
	}
	sort(startVec.begin(), startVec.end(), greater<int>());
	sort(endVec.begin(), endVec.end(),greater<int>());


}

int findAns()
{
	int ans = 0;
	ans += findMax();
	reMake();
	ans += findMax();

	return ans;
}



int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		//x값들을 없애기위해서 
		cin >> end >> end >> start >> start;
		rangeVec.push_back(make_pair(start, end));
		startVec.push_back(start);
		endVec.push_back(end);

		sort(rangeVec.begin(), rangeVec.end());
		sort(startVec.begin(), startVec.end(), greater<int>());
		sort(endVec.begin(), endVec.end() ,greater<int>());
	}

	for (int i = 0; i < rangeVec.size(); i++)
		rangeList.push_back(rangeVec[i]);


	cout << findAns() << endl;
	





	return 0;
}