//투포인터 알고리즘 사용
//각 알파벳의 갯수를 저장하는 배열이 존재.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define SUB 97
using namespace std;


int N;
string origin;


int twoPointer(int left = 0, int right = 1) {//[)범위
	vector<int> alphaNum(26, 0);

	int maxValue = -1;
	int ret = 1, count = 1;
	alphaNum[origin[0] - SUB]++;


	while (left < right && right<origin.size()) {
//		cout << "L :" << left << ' ' << "R : " << right << endl;

		//이미 값 있을 때 || 값이없는데 아직 count가 덜찼을때
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
		//나머지 경우들 -> 더이상 확장 불가능할 때, 왼쪽에서 댕겨옴
		else {
			maxValue = max(maxValue, ret);
			ret--;
			alphaNum[origin[left] - SUB]--;
			//댕겨온 곳에있을 알파벳이 서브문자열에 더 이상 존재하지 않는 경우에
			//카운트를 줄여줌
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