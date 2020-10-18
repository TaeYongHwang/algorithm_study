#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>


using namespace std;


int cache[10001];  //cache[i] : i번째부터 시작했을 때, 난이도의 최소합
				   //즉, cache[0]에 우리가 원하는 답이 저장된다.



//str에서 idx부터 num개를 잘라 난이도를 결정시켜준다.
int find_level(int num, int idx, string& str) {
	//case 1 : 모든 숫자가 같을 때 (난이도 1)
	int i;
	for (i = 1; i < num; i++) {
		if (str[idx] != str[idx + i]) //같지않은 숫자가 하나라도 있으면 i가 num에 도달하지 못함.
			break;
	}
	if (i == num)
		return 1;


	//case 2 : 모든 숫자가 단조 증가 or 단조 감소
	for (i = 0; i < num - 1; i++) {
		if (str[idx + i] != str[idx + i + 1] - 1)
			break;
	}
	if (i == num - 1)
		return 2;

	for (i = 0; i < num - 1; i++) {
		if (str[idx + i] != str[idx + i + 1] + 1)
			break;
	}
	if (i == num - 1)
		return 2;

	//case 3 : 두개의 숫자가 번갈아가면서 출현.
	if (num == 3) {
		if (str[idx] == str[idx + 2])
			return 4;
	}
	else if (num == 4) {
		if (str[idx] == str[idx + 2] && str[idx + 1] == str[idx + 3])
			return 4;
	}
	else {
		if (str[idx] == str[idx + 2] && str[idx]== str[idx + 4] && str[idx + 1] == str[idx + 3])
			return 4;
	}

	//case 4 : 숫자가 등차수열을 이룰 때.
	int temp = str[idx + 1] - str[idx];
	for (i = 1; i < num - 1; i++) {
		if (str[idx + i + 1] - str[idx + i] != temp)
			break;
	}
	if (i == num - 1)
		return 5;




	//아무 경우에도 속하지 않을 때.
	return 10;
}



int pi(int idx, string& str) {

	int &ret = cache[idx];




	
	//basecase 0 : 정확하게 str.size에 도달한경우 (이것만 정답으로 나오게됨.)
	if (idx == str.size()) {
		return 0;
	}

	//basecase 1 : 3개 이상 묶을 수 없을 때. (잘못된 경우)
	if (idx > str.size() - 3) {
		return 100000; //10000글자 이하기 때문에 난의도의 최대합이 33000을 넘을 수 없다.
	}
	//basecase 2 : 캐시가 이미 채워진 경우

	if (ret != -1)
		return ret;
		
	
	int min_value = 1000000;
	//3 ~5자리를 끊은 경우.
	for (int i = 3; i <= 5; i++) {
		if(idx+i <= str.size())
			min_value = min (min_value, find_level(i, idx, str)+ pi(idx + i, str));
	}

	
	return ret = min_value;
}





int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		string str;

		cin >> str;
		for (int i = 0; i < str.size(); i++)
			cache[i] = -1;
		
		cout << pi(0, str) << endl;

	}


	return 0;
}

