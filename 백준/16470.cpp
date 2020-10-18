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
		//�����Ͱ� �������
		if (cur.compare(country[i + 1]) == 0) {
			continue;
		} 
		//�ٸ����
		else {
			ans += count * count;
			count = 0;
		}

	}
	//��������
	if (cur.compare(country[country.size() - 1]) == 0) {
		count++;
	}
	//�ٸ����
	else {
		count = 1;		
	}
	ans += count * count;

	ans /= double(country.size()*country.size());


	return 1 - ans;

}




int main() {
	
	string temp;
	
	//���� ���Խ�Ų��.
	while (!cin.eof()) {
		cin >> temp;
		if (cin.eof())
			break;

		country.push_back(temp);
		
	}
	//���� ���Ľ�Ų��.
	sort(country.begin(), country.end());

	cout << findAns()<<endl;





	return 0;
}
