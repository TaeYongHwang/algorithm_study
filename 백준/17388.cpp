#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int S, K, H;
	cin >> S >> K >> H;

	if (S + K + H >= 100)
		cout << "OK" << endl;
	else {
		int minV = S;
		minV = min(minV, K);
		minV = min(minV, H);

		if (minV == S)
			cout << "Soongsil" << endl;
		else if (minV == K)
			cout << "Korea" << endl;
		else
			cout << "Hanyang" << endl;

	}



	return 0;
}