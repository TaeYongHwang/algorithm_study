#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector < pair <int, int> >  friends_pair;

int n, m; // n : �л� �� (¦��), m : ģ�� ���� ��


//�ߺ��Ǵ°� �ִ��� Ȯ�����ִ� �Լ�. => ������ T , ������ F
bool is_repeat(vector <int>& children)
{
	for (int i = 0; i < children.size(); i++) {
		for (int j = i+1; j < children.size(); j++) {
			if (children[i] == children[j])
				return true;
		}
	}
	return false;
}



int all_possible_cases(vector<int>& children, int start_idx, int num) //children : �ֵ� �ټ���� ��� (friends_pair�� �������), num : �ݺ��� Ƚ�� (n/2)
{
	int sum = 0;




	//base case : �ݺ�Ƚ���� ������ ��, �Ϸķ� ���� ���.
	//����� 1��ŭ �����ش�.
	if (num == 0) {		
		if (!is_repeat(children)) { //����
			return 1;
		}
		else {                      //����
			return 0;
		}
	}
	//start_idx�� num�� �Ѿ�� ��쿡 ����. (����1)
	if (start_idx > m)
		return 0;
	
	//num !=0
	for (int i = start_idx; i < m; i++)
	{
		int temp1 = friends_pair[i].first;
		int temp2 = friends_pair[i].second;
		
		children.push_back(temp1);
		children.push_back(temp2);
		sum += all_possible_cases(children, i + 1, num - 1);
		children.pop_back();
		children.pop_back();


	}
	return sum;
}





int main()
{
	int C; // C : �ݺ�Ƚ��
	vector <int> children;

	cin >> C;

	while (C--)
	{
		cin >> n >> m;
		int sum = 0;
		//m���� ���� v�� �־��.
		for(int i =0 ; i<m ;i++)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
			friends_pair.push_back(make_pair(temp1, temp2));
		}


		sum += all_possible_cases(children, 0, n / 2);
	

		cout << sum << endl;

		
		friends_pair.clear();
		



		


	}


	return 0;
}
