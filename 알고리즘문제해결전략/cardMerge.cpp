#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<long long > card; //ó���� ������ ��Ų �� ����(��������)


long long find_min(int count = 0)
{


	long long sum = 0;
	//basecase : count�� m������
	if (count == m) {
		for (int i = 0; i < card.size(); i++)
			sum += card[i];
		return sum;
	}

	//���� ���� �� ���ڸ� ����.
	long long temp1 = card.back();
	card.pop_back();
	long long temp2 = card.back();
	card.pop_back();

	//�� ���� ���� 
	sum = temp1 + temp2;

	//�� ���� �� ��ġ�� ã�Ƽ� �־���(2��)
	int i;
	for (i = card.size() - 1; i >= 0; i--) {
		if (card[i] >= sum) {
			card.insert(card.begin() + i + 1, 2, sum);

			break;
		}
	}

	if (i == -1)
		card.insert(card.begin(), 2, sum);

	return find_min(count + 1);


}




int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		card.push_back(temp);
	}
	sort(card.begin(), card.end(), greater<int>());


	cout << find_min() << endl;




	return 0;
}
