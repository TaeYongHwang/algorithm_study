#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int defalut_clock[16]; //default time
int cur_clock[16]; //�ٲ��.
vector <vector <int> > switch_clock(10, vector<int>());
int MIN = 1000;


//����ġ�� ���� Ƚ����ŭ �ð� �ð��� �����ϴ� �Լ�
void change_clock(vector <int>& switch_count)
{
	for (int i = 0; i < 10; i++) {
		int count_num = switch_count[i]; //�� ����ġ�� ���� Ƚ����  ���� ����
		if (count_num != 0) { //�ѹ��̶� ���� ��쿡�� ����
			while (count_num--) { //Ƚ���� 0�� �� ������ �ݺ�
				for (int j = 0; j < switch_clock[i].size(); j++)
				{
					//switch_clock[i][j]�� ����ִ� �� (����� �ð��)�� �ش��ϴ�
					//cur_clock[switch_clock[i][j]] ���� 3�� �÷��ش�			
					int clock_num = switch_clock[i][j]; //���⽱��
					cur_clock[clock_num] += 3;

					//���� ���� 15�� �Ǵ� ��쿡 3���� �����ϴ� �������
					if (cur_clock[clock_num] == 15) {
						cur_clock[clock_num] = 3;
					}
				}
			}
		}
	}
}

//��� �ð谡 12�ø� ����Ű���� Ȯ���ϴ� �Լ�
bool is_all_clock_12()
{
	for (int i = 0; i < 16; i++) {
		if (cur_clock[i] != 12)
			return false;
	}
	return true;
}


void all_switch_press(vector <int>& switch_count , int num = 0) //10�� ������ ������ �������
{
	//base case: ��� ��ư�� ���� ���� Ƚ���� ������ ���.
	if (num == 10) {
		//�ش� ��쿡��, ��� ����ġ�� ���� Ƚ���� MIN������ ū ��쿡, �� �̻� ����� �ʿ䰡 ����. 
		//�� ���� ���� ��� �ð踦 12�÷� ������� MIN���� ������� �ʱ� ������. 6248ms -> 4448ms
	
		int count = 0;
		for (int i = 0; i < 10; i++)
			count += switch_count[i];
		if (count > MIN)
			return;



		//1. default time���� �����ش�. 
		for (int i = 0; i < 16; i++)
			cur_clock[i] = defalut_clock[i];
		//2. �� ����ġ�� ���� Ƚ����ŭ �ð� �ð��� �ٲ��ش�.
		change_clock(switch_count);


		//3. ��� �ð谡 12�ø� ����Ű�� �� Ȯ���Ѵ�.
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

	//�� ����ġ�� ����� �ð���� ����
	

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
		//�ð� �ʱ�ȭ
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