#include <iostream>
#include <vector>
using namespace std;

int N;
int W;

vector<int> byteCoin;

//살수있는 코인 갯수 반환
long long buyCoin(long long  &curW, int day)
{
	long long div = curW / byteCoin[day];
	long long mod = curW % byteCoin[day];
	
	curW = mod; //현재 남은돈 업데이트
	return div;
}

//갖고있는 모든 코인을 팔 때 나오는 돈을 반환
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