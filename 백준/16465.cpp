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
	
	//�ϳ��� �ʿ���°�� (å�������� ���� å�� �ʺ�� �������)
	if (allBook == M)
		cout << 0 << endl;
	//�ϳ��� �ʿ��� ��� (���ƺ��� �ϳ��� �ʿ���)
	else if (L <M &&allBook<M && (allBook >= L || (M-allBook) >=L  ))
		cout << 1 << endl;
	//��������� -> -1
	else
		cout << -1 << endl;






	return 0;
}