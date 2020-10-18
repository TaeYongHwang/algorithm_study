#include <iostream>
#include <vector>
using namespace std;

vector <int> books;



int main()
{
	int N, M, L;
	int allBook = 0;
	cin >> N>> M>> L;


	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		//books.push_back(temp);
		allBook += temp;
	}
	
	//하나도 필요없는경우 (책사이즈의 합이 책장 너비와 같은경우)
	if (allBook == M)
		cout << 0 << endl;
	//하나가 필요한 경우 (많아봤자 하나만 필요함)
	else if (L <M &&allBook<M && (allBook >= L || (M-allBook) >=L  ))
		cout << 1 << endl;
	//나머지경우 -> -1
	else
		cout << -1 << endl;






	return 0;
}