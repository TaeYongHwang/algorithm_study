#include <iostream>
#include <vector>
using namespace std;

int N;
int W;

vector<int> byteCoin;

//����ִ� ���� ���� ��ȯ
long long buyCoin(long long  &curW, int day)
{
	long long div = curW / byteCoin[day];
	long long mod = curW % byteCoin[day];
	
	curW = mod; //���� ������ ������Ʈ
	return div;
}

//�����ִ� ��� ������ �� �� ������ ���� ��ȯ
long long sellCoin(long long &curCoinNum, int day) {

	long long ret = curCoinNum * byteCoin[day];
	curCoinNum = 0;
	return ret;

}





long long findMax()
{
	long long curW = W;
	long long curCoinNum = 0;
	int curCoinPrice = byteCoin[0];
	for (int i = 1; i < byteCoin.size(); i++) {
		if (curCoinPrice < byteCoin[i] ) {
			curCoinNum +=buyCoin(curW, i - 1);
			
		}
		else if (curCoinPrice > byteCoin[i]) {
			curW += sellCoin(curCoinNum, i-1);

		}

		curCoinPrice = byteCoin[i];

	}

	curW +=sellCoin(curCoinNum, N - 1);
	


	return curW;

}



int main()
{
	cin >> N >> W;
	byteCoin = vector<int>();

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		byteCoin.push_back(temp);
	}


	cout << findMax() << endl;






	return 0;
}