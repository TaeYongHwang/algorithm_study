#include <iostream>
#include <vector>
using namespace std;

int N; //원배열의 길이

vector<int> origin; //거꾸로 저장된다.
vector<int> sort;
vector<int> mov;


void find_origin(int size )
{
	if (size == 0)
		return;

	int mov_count = mov.back();
	mov.pop_back();

	int idx = size - 1 - mov_count;
	int number = sort[idx];
	origin.push_back(number);

	
	vector<int>::iterator it = sort.begin() + idx;
	sort.erase(it);


	find_origin(size - 1);

}







int main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			mov.push_back(temp);
			sort.push_back(i + 1);
		}

		find_origin(N);

		for (int i = origin.size() - 1; i >= 0; i--)
			cout << origin[i] << ' ';
		cout << endl;






		origin.clear();
		sort.clear();
		mov.clear();


	}


	return 0;
}