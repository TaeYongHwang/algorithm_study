#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int y;
list<pair<int, int>> rangeList;
vector< pair<int, int>> rangeVec; //���۰��� �������� ������������ ����
vector<int> startVec; //���۰��� ������������ �����Ұ�.
vector<int> endVec;   //������ ������������ �����Ұ�.

int findMax() {
	int maxValue = -1, curValue =0, open = -1, close = -1;
	int yValue;
	while (!startVec.empty()) {

		//�����ߵǴ� ���� ���� -1�� �ʱ�ȭ���ѵд�.(while�� ��������)
		if (open == -1) {
			open = startVec.back();
			startVec.pop_back();

		}
		if (close == -1) {
			close = endVec.back();
			endVec.pop_back();
		}

		//�񱳹�
		if (open <= close) { //���������� �ϳ��� �� �������
			curValue++;
			open = -1;
			continue;
		} else { //���������� �ϳ��� �� �������
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

//y������ؼ�, �װ����ִ� ������ ��� ������Ų��.
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
		//x������ ���ֱ����ؼ� 
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