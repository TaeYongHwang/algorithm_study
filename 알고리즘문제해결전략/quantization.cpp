#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //�ݿø��Լ� ����ϱ� ����
using namespace std;

int N,S; //������ ����, ����� ������ ��
vector <int> v; //���Ľ��Ѿߵȴ�. (��������)

int cache[100][11]; //cache[i][j] : i��°���������� ���ڸ� j���� ������ ���� ���� ������ ���� �ּ�
					//�� j<S�� �͵� �߿� �ּҸ� ã���� �ȴ�.



int min_error_square_sum(const int start_idx, const int end_idx) { //[)����
	//��հ��� �ݿø��� ���� ����
	double temp= 0;
	int sum = 0;
	for (int i = start_idx; i < end_idx; i++) {
		temp += v[i];
	}

	//�� ���� ����ȭ�Ǵ� ����.
	int average = round(temp / (end_idx - start_idx));

	//���� ������ ���� ���Ѵ�.
	for (int i = start_idx; i < end_idx; i++) {
		sum += pow((average - v[i]), 2);

	}

	return sum;

}

//���������� ���� �ִ밡 100000000(1��)�� ���� �ʴ´�.
int find_min(int idx, int num_of_quan =1) {
	
	//basecase : S�� �Ѿ�µ�, ���� �������� ���� ��� (����)
	if (num_of_quan > S ) {
		return 987654321;
	}



	//basecase : num_of_quan == S�� �� ���
	//OR �������� ������ ���
	//���� ������ ��� ������ �� ���.
	if (num_of_quan == S || idx == N-1) {
		//cout << "idx:" << idx << ' ' << "quan : " << num_of_quan << endl;
		return min_error_square_sum(idx, N);
	}

	int &ret = cache[idx][num_of_quan];
	//basecase : �̹� ����� ���
	if (ret != -1)
		return ret;

	//�⺻ ����... �ش� �ε����� ��������, ������ ���� �� �ִ� ��� ����� ���� ���� �غ�����.
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