#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, K;

//list에 두명만 남을 때까지 반복
void remain_two(int num, list<int>& li, list<int>::iterator & iter) {


	//basecase : 2명남은경우
	if (num == 2)
		return;

	//N번 째 병사를 리스트에서 없앤다.
	//삭제 시 다음 번호로 넘어가기 때문에 반복문에서는 k-1번만 수행한다.
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
		//1번은 이미 자살
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












