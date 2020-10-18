#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int change_score(int cur)
{
	if (cur == 100)
		return 100;

	int units = cur % 10;
	int tens = cur/ 10;

	
	if (units == 0)
		cur+= 9;
	else if (units == 6)
		cur+= 3;
	
	if (tens == 6)
		cur += 30;



	return cur;
}



int main()
{
	int N;
	cin >> N;

	double sum = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sum += change_score(temp);
	}


	cout << floor(sum / N + 0.5)<<endl;



	return 0;
}