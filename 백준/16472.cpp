//�������� �˰��� ���
//�� ���ĺ��� ������ �����ϴ� �迭�� ����.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define SUB 97
using namespace std;


int N;
string origin;


int twoPointer(int left = 0, int right = 1) {//[)����
	vector<int> alphaNum(26, 0);

	int maxValue = -1;
	int ret = 1, count = 1;
	alphaNum[origin[0] - SUB]++;


	while (left < right && right<origin.size()) {
//		cout << "L :" << left << ' ' << "R : " << right << endl;

		//�̹� �� ���� �� || ���̾��µ� ���� count�� ��á����
		if (alphaNum[origin[right] - SUB] != 0 ) {
			ret++;
			alphaNum[origin[right] - SUB]++;
			right++;
		}
		else if (count < N) {
			count++;
			ret++;
			alphaNum[origin[right] - SUB]++;
			right++;
		}
		//������ ���� -> ���̻� Ȯ�� �Ұ����� ��, ���ʿ��� ��ܿ�
		else {
			maxValue = max(maxValue, ret);
			ret--;
			alphaNum[origin[left] - SUB]--;
			//��ܿ� �������� ���ĺ��� ���깮�ڿ��� �� �̻� �������� �ʴ� ��쿡
			//ī��Ʈ�� �ٿ���
			if (alphaNum[origin[left] - SUB] == 0)
				count--;
			left++;
		}
	
	}
	maxValue = max(maxValue, ret);
	return maxValue;

}





int main() {
	cin >> N >> origin;

	cout << twoPointer() << endl;



	return 0;
}