#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//���� ����
//�κ����� ����, �������� ������
bool is_ans(const int k){
	//Ȧ���� ��� ������ ���� �� �ִ�.
	if (k % 2 == 1)
		return true;

	//¦���� ���
	int value = k-1, count = 1;
	while (value > 0) {
		count++;
		value -= count;
		if (value % count == 0) {
			return true;
		}
	}

	return false;
}





int main()
{
	int C;
	cin >> C;
	while (C--) {
		int K;
		cin >> K;
		if (is_ans(K))
			cout << "Gazua" << endl;
		else
			cout << "GoHanGang" << endl;

	}


	return 0;
}
