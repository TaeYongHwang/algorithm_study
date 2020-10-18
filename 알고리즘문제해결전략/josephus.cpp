#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, K;

//list�� �θ� ���� ������ �ݺ�
void remain_two(int num, list<int>& li, list<int>::iterator & iter) {


	//basecase : 2�������
	if (num == 2)
		return;

	//N�� ° ���縦 ����Ʈ���� ���ش�.
	//���� �� ���� ��ȣ�� �Ѿ�� ������ �ݺ��������� k-1���� �����Ѵ�.
	for (int i = 1; i <= K-1; i++) {
		iter++;
		if (iter == li.end())
			iter = li.begin();
		
	}
	
	li.erase(iter++);
	if (iter == li.end())
		iter = li.begin();
	
	remain_two(num - 1, li, iter);
	return;

}





int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> N >> K;


		list <int> li;
		//1���� �̹� �ڻ�
		for (int i = 2; i <= N; i++)
			li.push_back(i);

		list<int>::iterator iter = li.begin();
		remain_two(N-1, li, iter);
		
		for (iter = li.begin(); iter != li.end(); iter++)
			cout << *iter << ' ';
		cout << endl;
		

		
	}
	return 0;
}












