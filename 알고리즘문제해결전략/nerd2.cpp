#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N; //���� ��û�� ����� ��
map <int, int> people; //����, �׸� ��  (���ĵ��ִٰ���)


bool is_dominated(int cur_prob, int cur_dish)
{
	map<int, int>::iterator it = people.upper_bound(cur_prob);

	if (it == people.end())
		return false;

	return cur_dish < it->second;
}

void remove_dominated(int cur_prob, int cur_dish)
{
	map<int, int>::iterator it = people.lower_bound(cur_prob);
	if (it == people.begin())
		return;

	it--;
	while (true) {
		if (it->second > cur_dish)
			break;
		if (it == people.begin()) {
			people.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			people.erase(it);
			it = jt;
		}

	}



}

int find_num(int cur_prob, int cur_dish)
{
	//�ش� ���� �̹� ������ϴ� ��� �׳� ��ȯ(�߰�����)
	if (is_dominated(cur_prob, cur_dish))
		return people.size();

	remove_dominated(cur_prob, cur_dish);
	people.insert(make_pair(cur_prob, cur_dish));

	
	return people.size();
}






int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> N;
		int sum = 0;

		for (int i = 0; i < N; i++) {
			int prob, dish;
			scanf("%d %d", &prob, &dish);
			sum+=find_num(prob, dish);



		}

		cout << sum << endl;
		

		people.clear();




	}


	return 0;


}