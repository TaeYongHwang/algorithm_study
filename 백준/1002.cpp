//��ġ�� ��
//�� ���� ��ġ�� ���� ������ ����.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

pair <int, pair<int, int>> c1;
pair <int, pair<int, int>> c2;


double findDist(int x1, int x2, int y1, int y2) {
	return (double)sqrt((double)pow((double)x1 - x2, 2) + (double)pow((double)y1 - y2, 2));
}



int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> c1.second.first;
		cin >> c1.second.second;
		cin >> c1.first;

		cin >> c2.second.first;
		cin >> c2.second.second;
		cin >> c2.first;

		int &r1 = c1.first;
		int &r2 = c2.first;
		int &x1 = c1.second.first;
		int &x2 = c2.second.first;
		int &y1 = c1.second.second;
		int &y2 = c2.second.second;

		//���Ѵ��� ��� -> �ƿ� ������ ��
		if (r1 == r2 && x1 == x2 && y1 == y2) {
			cout << -1;
		} //1���ΰ�� -> ���� or ����
		else if (findDist(x1,x2,y1,y2) == (r1 + r2) || findDist(x1,x2,y1,y2) == abs(r1 -r2)) {
			cout << 1;
		} //2���ΰ�� -> �׻���
		else if (findDist(x1, x2, y1, y2) < (r1 + r2) && findDist(x1,x2,y1,y2)> abs(r1-r2)  ) {
			cout << 2;
		} //���°��
		else {
			cout << 0;
		}
		cout << endl;






	}
	return 0;

}