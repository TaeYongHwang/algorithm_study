#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //반올림함수 사용하기 위함
using namespace std;

int N,S; //수열의 길이, 사용할 숫자의 수
vector <int> v; //정렬시켜야된다. (오름차순)

int cache[100][11]; //cache[i][j] : i번째에서까지의 숫자를 j개로 묶었을 때의 오차 제곱의 합의 최소
					//즉 j<S인 것들 중에 최소를 찾으면 된다.



int min_error_square_sum(const int start_idx, const int end_idx) { //[)범위
	//평균값을 반올림한 값을 구함
	double temp= 0;
	int sum = 0;
	for (int i = start_idx; i < end_idx; i++) {
		temp += v[i];
	}

	//이 값이 양자화되는 값임.
	int average = round(temp / (end_idx - start_idx));

	//오차 제곱의 합을 구한다.
	for (int i = start_idx; i < end_idx; i++) {
		sum += pow((average - v[i]), 2);

	}

	return sum;

}

//오차제곱의 합은 최대가 100000000(1억)을 넘지 않는다.
int find_min(int idx, int num_of_quan =1) {
	
	//basecase : S가 넘어가는데, 끝에 도달하지 못한 경우 (예외)
	if (num_of_quan > S ) {
		return 987654321;
	}



	//basecase : num_of_quan == S가 된 경우
	//OR 마지막에 도달한 경우
	//남은 값들을 모두 묶어준 후 계산.
	if (num_of_quan == S || idx == N-1) {
		//cout << "idx:" << idx << ' ' << "quan : " << num_of_quan << endl;
		return min_error_square_sum(idx, N);
	}

	int &ret = cache[idx][num_of_quan];
	//basecase : 이미 계산한 경우
	if (ret != -1)
		return ret;

	//기본 계산들... 해당 인덱스를 시작으로, 끝까지 묶을 수 있는 모든 경우의 수에 대해 해봐야함.
	int min_value = 987654321;
	for (int i = idx; i < N; i++) {
		min_value = min(min_value, min_error_square_sum(idx, i + 1) + find_min(i + 1, num_of_quan + 1));
	}

	return ret = min_value;

}




int main()
{
	int C;
	cin >> C;
	while (C--) {
		v.clear();
		cin >> N >> S;
		for (int i = 0; i < N; i++) {
			
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= S; j++) {
				cache[i][j] = -1;
			}
		}


		sort(v.begin(), v.end());
	
			cout<<find_min(0)<<endl;

	}	
	return 0;
}