#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> me;
vector<int> you;

void findPossibility() {
	int yourCard;
	int myCard;
	int myIdx = me.size()-1;
	int winCount =0;

	while (1) {
		yourCard = you.back();
		you.pop_back();
	

		for (myIdx;  myIdx >= 0 && me[myIdx] >= yourCard; myIdx--) {
			//�ε����� ������ ī�庸�� ū ���� ���ö����� ����.
		}

		if (myIdx != -1) {
			winCount++;
			myIdx--; //���� �� ī�嵵 �������ϱ⶧����
			continue;
		}
		else {
			break;
		}
	}
	
	//cout<<winCount<<endl;
	
	if (winCount >= ((N + 1) / 2)) {
		cout << "YES"<<endl;
	}
	else
		cout << "NO" << endl;



}




int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		me.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		you.push_back(temp);
	}
	sort(me.begin(), me.end());
	sort(you.begin(), you.end());

	findPossibility();

	return 0;

}