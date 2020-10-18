#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector< string > country;


double findAns()
{
	int count = 0;
	double ans = 0;
	string cur;
	for (int i = 0; i < country.size()-1; i++) {
		cur = country[i];
		count++;
		//다음것과 같은경우
		if (cur.compare(country[i + 1]) == 0) {
			continue;
		} 
		//다른경우
		else {
			ans += count * count;
			count = 0;
		}

	}
	//마지막꺼
	if (cur.compare(country[country.size() - 1]) == 0) {
		count++;
	}
	//다른경우
	else {
		count = 1;		
	}
	ans += count * count;

	ans /= double(country.size()*country.size());


	return 1 - ans;

}




int main() {
	
	string temp;
	
	//값을 대입시킨다.
	while (!cin.eof()) {
		cin >> temp;
		if (cin.eof())
			break;

		country.push_back(temp);
		
	}
	//값을 정렬시킨다.
	sort(country.begin(), country.end());

	cout << findAns()<<endl;





	return 0;
}
