#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool is_correct(string& str)
{
	stack <char> S;

	for (int i = 0; i < str.size(); i++) {
		
		char c = str[i];

		//¿©´Â°ýÈ£ÀÎ°æ¿ì
		if (c == '(' || c == '[' || c == '{') {
			S.push(c);
		}
		else {

			//½ºÅÃÀÌ ºó°æ¿ì
			if (S.size() == 0)
				return false;

			//´Ý´Â °ýÈ£ÀÎ °æ¿ì
			char open_brac = S.top();
			S.pop();

			if (open_brac == '(' && c == ')')
				continue;
			else if (open_brac == '['  && c == ']')
				continue;
			else if (open_brac == '{' && c == '}')
				continue;
			else
				return false;
		}

	}

	if (S.size() != 0)
		return false;

	return true;


}





int main()
{
	int C;
	cin >> C;
	while (C--) 
	{
		string str;
		cin >> str;

		if (is_correct(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}






	return 0;
}