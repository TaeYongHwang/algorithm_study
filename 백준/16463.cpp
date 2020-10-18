#include <iostream>
#include <vector>
using namespace std;

#define NEXTDAY 7

bool is_leapyear(const int year) {
	if (year % 400 == 0)
		return true;

	else if (year % 400 != 0 && year % 100 == 0)
		return false;

	else if (year % 100 != 0 && year % 4 == 0)
		return true;
	else
		return false;

}

void find_next_friday(int &year, int & month, int & day) {
	int mod;

	switch (month) {
		//31일
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			mod = 31; 
			break;
		//30일
		case 4:
		case 6:
		case 9:
		case 11:
			mod = 30;
			break;

		//28 or 29
		case 2:
			if (is_leapyear(year))
				mod = 29;
			else
				mod = 28;
			break;
	}


	//월을 넘어가는 경우
	day += NEXTDAY;
	if (day / (mod+1) != 0) {
		day = day % mod;
		month++;

		//월을 넘어가는 경우
		if (month / 13 != 0) {
			month = 1;
			year++;
		}
	}

}






int find_ans(int N)
{	

	int curYear = 2019;
	int curMonth = 1;
	int curDay = 4;
	int sum = 0;

	while (curYear <= N) {
		find_next_friday(curYear, curMonth, curDay);
		if (curDay == 13)
			sum++;
	}

	return sum;
}



int main()
{
	int N;
	cin >> N;

	
	cout << find_ans(N) << endl;

	return 0;
}