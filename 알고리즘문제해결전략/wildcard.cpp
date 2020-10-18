#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//파일명이 와일드카드에 대응되는지 확인하는 함수.
int compare(string file, string wildcard)
{
	//cout << "file :" << file << ' ' << "wildcard: " << wildcard << endl;

	int count = 0;

	//basecase 1 : 더 이상 wildcard에 문자열이 존재하지 않는 경우.
	if (wildcard.empty())
	{
		if (file.empty()) 		//file에 아무 문자열도 존재하지 않는 경우
			return 1;
		else
			return 0;			//file에 어떤 문자라도 존재하는 경우
	
	}




	//basecase 2 : 더 이상 file에 문자열이 존재하지 않는 경우
	if (file.empty())
	{
		//*을 제외한 문자열이 wildcard에 존재하는 경우
		//*을 제외한 문자열이 wildcard에 존재하지 않는 경우.
		for (int i = 0; i < wildcard.size(); i++) {
			if (wildcard[i] != '*')
				return 0;
		}
		return 1;

	}


	//이 부분부터는 결국 wildcard와 file에 문자가 하나라도 있어야지 들어올 수 있다.

	//case 1 : '?'를 만난 경우
	//무조건 분기
	if ( wildcard.front() == '?' ) {

		count+= compare(file.substr(1), wildcard.substr(1));
		if (count != 0)
			return 1;
	}
	else if (wildcard.front() == '*') {
		//case 2 : '*'을 만난 경우 -> file의 끝까지 가는 모든 경우의 수에 대해 해봄.
		for (int i = 0; i <= file.size(); i++) {


			count += compare(file.substr(i), wildcard.substr(1));
			if (count != 0)
				return 1;
		}


	} else {
		//case 3 : 나머지 문자열 (숫자, 대문자, 소문자 만난 경우)
		if (file.front() == wildcard.front()) {
			count += compare(file.substr(1), wildcard.substr(1));
		}
		else
			return 0; //실패
	}

	return count;
}





int main()
{
	int C;
	cin >> C;
	
	while (C--)
	{
		vector<string> v;
		string wildcard;
		string file;
		int N;
		cin >> wildcard;
		cin >> N;
		while (N--)
		{
			cin >> file;  
			if (compare(file, wildcard) != 0)
				v.push_back(file);
		}
		
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
	}





	return 0;
}

