#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> story;
string whoStr, whereStr, whatStr;


//wordNum 은 who : 2, what : 3, where: 4
string changePart(string str, int pos , int wordNum)
{

	string ans = "";

	for (int i = 0; i < pos; i++) {
		ans += str[i];
	}

	if (wordNum == 3)
		ans += whoStr;
	else if (wordNum == 4)
		ans += whatStr;
	else if (wordNum == 5)
		ans += whereStr;

	for (int i = pos + wordNum; i < str.size(); i++)
		ans += str[i];
	
	
	return ans;
}


void changeStr() {
	string WHO = "WHO";
	string WHERE = "WHERE";
	string WHAT = "WHAT";
	
	string ans = "";

	for (int i = 0; i < story.size(); i++) {
		// what, where, who순으로검사 (포함관계)
		string changingStr = story[i];
		
		int pos;

		if ((pos = changingStr.find(WHAT)) != string::npos) {
			changingStr = changePart(changingStr, pos, 4);
			//cout << changingStr << endl;
		}

		if ((pos = changingStr.find(WHERE)) != string::npos) {

			changingStr = changePart(changingStr, pos, 5);
			//cout << changingStr << endl;
		}

		if ( (pos = changingStr.find(WHO)) != string::npos) {
		//	cout << "pos :" << pos << endl;
			changingStr = changePart(changingStr, pos , 3);
		//	cout << changingStr << endl;
		}
	
		ans += changingStr + '\n';
	}




	cout << ans << endl;


}







int main()
{
	string temp;

	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (1) {
		getline(cin, temp);
		//줄거리 끝에도달.
		if (temp[0] == '0') {
			break;
		}
		story.push_back(temp);

	}
	
	


	getline(cin, whoStr);
	getline(cin, whereStr);
	getline(cin, whatStr);

//	cout << story[0] << endl;

	//cout << whoStr <<endl<< whereStr <<endl<< whatStr << endl;

	changeStr();
	








	return 0;
}