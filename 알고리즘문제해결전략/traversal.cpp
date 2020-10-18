#include <iostream>
#include <vector>
using namespace std;

int N; //트리에 포함된 노드의 수

vector<int> pre_order;
vector<int> in_order;
int root_idx = 0;


void print_post_order(int left, int right) { //[)범위
	
	if (root_idx == N)
		return;

	int root = pre_order[root_idx++];

	//in_order에서 root값의 인덱스를 찾아내야 됨.
	int idx;
	for (idx = 0; idx < in_order.size(); idx++) {
		if (in_order[idx] == root)
			break;
	}

	//left, right를 이용해 왼쪽 오른쪽 갯수를 구한다.
	int left_num = idx - left;
	int right_num = right - (idx+1);


	if (left_num != 0)
		print_post_order(left, left + left_num);

	if (right_num != 0)
		print_post_order(right - right_num, right);


	cout << root << ' ';


}








int main()
{
	int C;
	cin >> C;
	while (C--) 
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			pre_order.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			in_order.push_back(temp);
		}
		root_idx = 0;


		print_post_order(0, in_order.size());






		in_order.clear();
		pre_order.clear();


	}

	return 0;
}