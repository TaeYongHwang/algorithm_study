#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>


using namespace std;


int cache[10001];  //cache[i] : i��°���� �������� ��, ���̵��� �ּ���
				   //��, cache[0]�� �츮�� ���ϴ� ���� ����ȴ�.



//str���� idx���� num���� �߶� ���̵��� ���������ش�.
int find_level(int num, int idx, string& str) {
	//case 1 : ��� ���ڰ� ���� �� (���̵� 1)
	int i;
	for (i = 1; i < num; i++) {
		if (str[idx] != str[idx + i]) //�������� ���ڰ� �ϳ��� ������ i�� num�� �������� ����.
			break;
	}
	if (i == num)
		return 1;


	//case 2 : ��� ���ڰ� ���� ���� or ���� ����
	for (i = 0; i < num - 1; i++) {
		if (str[idx + i] != str[idx + i + 1] - 1)
			break;
	}
	if (i == num - 1)
		return 2;

	for (i = 0; i < num - 1; i++) {
		if (str[idx + i] != str[idx + i + 1] + 1)
			break;
	}
	if (i == num - 1)
		return 2;

	//case 3 : �ΰ��� ���ڰ� �����ư��鼭 ����.
	if (num == 3) {
		if (str[idx] == str[idx + 2])
			return 4;
	}
	else if (num == 4) {
		if (str[idx] == str[idx + 2] && str[idx + 1] == str[idx + 3])
			return 4;
	}
	else {
		if (str[idx] == str[idx + 2] && str[idx]== str[idx + 4] && str[idx + 1] == str[idx + 3])
			return 4;
	}

	//case 4 : ���ڰ� ���������� �̷� ��.
	int temp = str[idx + 1] - str[idx];
	for (i = 1; i < num - 1; i++) {
		if (str[idx + i + 1] - str[idx + i] != temp)
			break;
	}
	if (i == num - 1)
		return 5;




	//�ƹ� ��쿡�� ������ ���� ��.
	return 10;
}



int pi(int idx, string& str) {

	int &ret = cache[idx];




	
	//basecase 0 : ��Ȯ�ϰ� str.size�� �����Ѱ�� (�̰͸� �������� �����Ե�.)
	if (idx == str.size()) {
		return 0;
	}

	//basecase 1 : 3�� �̻� ���� �� ���� ��. (�߸��� ���)
	if (idx > str.size() - 3) {
		return 100000; //10000���� ���ϱ� ������ ���ǵ��� �ִ����� 33000�� ���� �� ����.
	}
	//basecase 2 : ĳ�ð� �̹� ä���� ���

	if (ret != -1)
		return ret;
		
	
	int min_value = 1000000;
	//3 ~5�ڸ��� ���� ���.
	for (int i = 3; i <= 5; i++) {
		if(idx+i <= str.size())
			min_value = min (min_value, find_level(i, idx, str)+ pi(idx + i, str));
	}

	
	return ret = min_value;
}





int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		string str;

		cin >> str;
		for (int i = 0; i < str.size(); i++)
			cache[i] = -1;
		
		cout << pi(0, str) << endl;

	}


	return 0;
}

