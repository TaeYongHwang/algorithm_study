#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int defalut_clock[16]; //default time
int cur_clock[16]; //바뀐다.
vector <vector <int> > switch_clock(10, vector<int>());
int MIN = 1000;


//스위치를 누른 횟수만큼 시계 시간을 변경하는 함수
void change_clock(vector <int>& switch_count)
{
	for (int i = 0; i < 10; i++) {
		int count_num = switch_count[i]; //각 스위치를 누른 횟수를  따로 저장
		if (count_num != 0) { //한번이라도 누른 경우에만 실행
			while (count_num--) { //횟수가 0이 될 때까지 반복
				for (int j = 0; j < switch_clock[i].size(); j++)
				{
					//switch_clock[i][j]에 들어있는 값 (연결된 시계들)에 해당하는
					//cur_clock[switch_clock[i][j]] 값을 3씩 올려준다			
					int clock_num = switch_clock[i][j]; //보기쉽게
					cur_clock[clock_num] += 3;

					//만약 값이 15가 되는 경우에 3으로 변경하는 방식으로
					if (cur_clock[clock_num] == 15) {
						cur_clock[clock_num] = 3;
					}
				}
			}
		}
	}
}

//모든 시계가 12시를 가리키는지 확인하는 함수
bool is_all_clock_12()
{
	for (int i = 0; i < 16; i++) {
		if (cur_clock[i] != 12)
			return false;
	}
	return true;
}


void all_switch_press(vector <int>& switch_count , int num = 0) //10에 도달한 순간이 기저사례
{
	//base case: 모든 버튼에 대해 누른 횟수가 정해진 경우.
	if (num == 10) {
		//해당 경우에서, 모든 스위치를 누른 횟수가 MIN값보다 큰 경우에, 더 이상 계산할 필요가 없다. 
		//그 값이 설령 모든 시계를 12시로 만들더라도 MIN값이 변경되지 않기 때문에. 6248ms -> 4448ms
	
		int count = 0;
		for (int i = 0; i < 10; i++)
			count += switch_count[i];
		if (count > MIN)
			return;



		//1. default time으로 맞춰준다. 
		for (int i = 0; i < 16; i++)
			cur_clock[i] = defalut_clock[i];
		//2. 각 스위치를 누른 횟수만큼 시계 시간을 바꿔준다.
		change_clock(switch_count);


		//3. 모든 시계가 12시를 가리키는 지 확인한다.
		if (is_all_clock_12()) {

			MIN = min(count, MIN);
			return;
		}
		else
			return;
	}

	for (int i = 0; i < 4; i++)
	{
		switch_count.push_back(i);
		all_switch_press(switch_count, num+1);
		switch_count.pop_back();
	}

	return;
}




int main()
{
	int C;
	cin >> C;

	//각 스위치에 연결된 시계들을 정리
	

	switch_clock[0].push_back(0);
	switch_clock[0].push_back(1);
	switch_clock[0].push_back(2);

	switch_clock[1].push_back(3);
	switch_clock[1].push_back(7);
	switch_clock[1].push_back(9);
	switch_clock[1].push_back(11);

	switch_clock[2].push_back(4);
	switch_clock[2].push_back(10);
	switch_clock[2].push_back(14);
	switch_clock[2].push_back(15);

	switch_clock[3].push_back(0);
	switch_clock[3].push_back(4);
	switch_clock[3].push_back(5);
	switch_clock[3].push_back(6);
	switch_clock[3].push_back(7);

	switch_clock[4].push_back(6);
	switch_clock[4].push_back(7);
	switch_clock[4].push_back(8);
	switch_clock[4].push_back(10);
	switch_clock[4].push_back(12);

	switch_clock[5].push_back(0);
	switch_clock[5].push_back(2);
	switch_clock[5].push_back(14);
	switch_clock[5].push_back(15);

	switch_clock[6].push_back(3);
	switch_clock[6].push_back(14);
	switch_clock[6].push_back(15);

	switch_clock[7].push_back(4);
	switch_clock[7].push_back(5);
	switch_clock[7].push_back(7);
	switch_clock[7].push_back(14);
	switch_clock[7].push_back(15);

	switch_clock[8].push_back(1);
	switch_clock[8].push_back(2);
	switch_clock[8].push_back(3);
	switch_clock[8].push_back(4);
	switch_clock[8].push_back(5);

	switch_clock[9].push_back(3);
	switch_clock[9].push_back(4);
	switch_clock[9].push_back(5);
	switch_clock[9].push_back(9);
	switch_clock[9].push_back(13);




	while (C--)
	{
		//시계 초기화
		for (int i = 0; i < 16; i++)
			cin >> defalut_clock[i];


		vector<int> v;

		all_switch_press(v);
		if (MIN == 1000)
			cout << -1 << endl;
		else
			cout << MIN<<endl;

		MIN = 1000;
	}
	
	return 0;
}