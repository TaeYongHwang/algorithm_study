#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;


//뒤에서부터시작
int findAns(int idx,vector<int> op , bool isMin) {
	int minV = 1100000000;
	int maxV = -1100000000;

	if (idx == 0) {
		return numbers[idx];

	}

	//+ - X /
	for (int i = 0; i < op.size(); i++) { //4번반복
		if (op[i] != 0) {
			op[i]--;
			int temp;
			switch (i) {
				case 0: //+
					temp = findAns(idx - 1, op,isMin) + numbers[idx];
					break;

				case 1: // -
					temp = findAns(idx - 1, op, isMin) - numbers[idx];
					break;

				case 2: // X
					temp = findAns(idx - 1, op, isMin) * numbers[idx];
					break;

				case 3: // /
					temp = findAns(idx - 1, op, isMin) / numbers[idx];
					break;
					
			}
			op[i]++;

			if(isMin)
				minV = min(minV, temp);
			else
				maxV = max(maxV, temp);

		}


	}

	if (isMin)
		return minV;
	else
		return maxV;

}



int main() {
	vector<int> op;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		op.push_back(temp);
	}

	cout << findAns(numbers.size() - 1, op, false)<<endl;
	cout << findAns(numbers.size() - 1, op, true) << endl;



	return 0;
}