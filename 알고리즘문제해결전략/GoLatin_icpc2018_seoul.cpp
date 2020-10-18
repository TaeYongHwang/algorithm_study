#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> words;

string changeLatin(string word)
{
	string ans ="";
	ans.append(word);

	char e1C = word[word.size()-1];
	char e2C = word[word.size() - 2];

	if (e1C == 'a' || e1C =='o' || e1C== 'u')
		ans.append("s");
	else if (e1C == 'i' || e1C == 'y') {
		ans.pop_back();
		ans.append("ios");
	}
	else if (e1C == 'l' || e1C =='r' || e1C =='v')
		ans.append("es");
	else if (e1C == 'n') {
		ans.pop_back();
		ans.append("anes");
	}
	else if (e2C == 'n' && e1C == 'e') {
		ans.pop_back();
		ans.pop_back();
		ans.append("anes");
	}
	else if (e1C == 't' || e1C=='w') {
		ans.append("as");
	}
	else {
		ans.append("us");
	}
	return ans;
}






int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	for (int i = 0; i < words.size(); i++) {
		cout << changeLatin(words[i]) << endl;
	}


	
}