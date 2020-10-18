#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector < pair <int, int> >  friends_pair;

int n, m; // n : 학생 수 (짝수), m : 친구 쌍의 수


//중복되는게 있는지 확인해주는 함수. => 있으면 T , 없으면 F
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



int all_possible_cases(vector<int>& children, int start_idx, int num) //children : 애들 줄세우는 경우 (friends_pair를 순서대로), num : 반복할 횟수 (n/2)
{
	int sum = 0;




	//base case : 반복횟수가 끝났을 때, 일렬로 세운 경우.
	//결과에 1만큼 더해준다.
	if (num == 0) {		
		if (!is_repeat(children)) { //성공
			return 1;
		}
		else {                      //실패
			return 0;
		}
	}
	//start_idx가 num을 넘어가는 경우에 종료. (실패1)
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
	int C; // C : 반복횟수
	vector <int> children;

	cin >> C;

	while (C--)
	{
		cin >> n >> m;
		int sum = 0;
		//m개의 쌍을 v에 넣어둠.
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
