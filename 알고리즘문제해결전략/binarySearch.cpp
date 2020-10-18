#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearch(vector<int> arr, int value);

int main() {
	vector<int> arr;
	srand((unsigned int)time(NULL));

	//////////////////////////////////
	//
	// test1. single element array test
	//
	cout << "test1...   ";
	arr.push_back(5);
	if (binarySearch(arr, 5) != 0) {
		cout << "test1 failed" << endl;
		return 0;
	}
	cout << "passed" << endl;
	arr.clear();
	//////////////////////////////////
	//
	// test2. two elements array test
	//
	arr.push_back(3);
	arr.push_back(7);
	cout << "test2 : two elements array test...   ";
	if (binarySearch(arr, 3) != 0) {
		cout << "test2 failed" << endl;
		return 0;
	}
	if (binarySearch(arr, 7) != 1) {
		cout << "test2 failed" << endl;
		return 0;
	}
	cout << "passed" << endl;
	arr.clear();
	//////////////////////////////////
	//
	// test3. odd number elements array test
	//
	cout << "test3 : odd number elements array test...   ";
	for (int i = 0; i < 9; i++) {
		arr.push_back(i * 5 + (rand() % 3));
	}
	for (int i = 0; i < 9; i++) {
		if (binarySearch(arr, arr[i]) != i) {
			cout << "test3 failed" << endl;
			return 0;
		}
	}
	cout << "passed" << endl;
	arr.clear();
	//////////////////////////////////
	//
	// test4. even number elements array test
	//
	cout << "test4 : even number elements array test...   ";
	for (int i = 0; i < 10; i++) {
		arr.push_back(i * 5 + (rand() % 3));
	}
	for (int i = 0; i < 10; i++) {
		if (binarySearch(arr, arr[i]) != i) {
			cout << "test4 failed" << endl;
			return 0;
		}
	}
	cout << "passed" << endl;
	arr.clear();
}

////////////////////////////////////////
//
// �־��� �迭���� ����Ž���� �̿��� value�� ã�� index�� ��ȯ
// ���� value�� �������� �ʴ´ٸ� -1�� ��ȯ
// �迭�� ������������ ���ĵǾ��ִ�
// �ߺ��Ǵ� ���Ҵ� ����
//
////////////////////////////////////////

int binarySearch(vector<int> arr, int value) {
	int mid = arr.size() / 2;
	int startIdx = 0, endIdx = arr.size()-1;
	while (startIdx <= endIdx)
	{
		if (startIdx == endIdx && arr[mid] != value)
			return -1;

		if (arr[mid] == value)
			return mid;
		else if (value < arr[mid])
		{
			endIdx = mid;
			mid = (startIdx + endIdx) / 2;
			continue;
		}
		else
		{
			startIdx = mid + 1;
			mid = (startIdx + endIdx) / 2;
			continue;
		}
	}
	
	return -1;
}