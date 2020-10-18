#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//���ϸ��� ���ϵ�ī�忡 �����Ǵ��� Ȯ���ϴ� �Լ�.
int compare(string file, string wildcard)
{
	//cout << "file :" << file << ' ' << "wildcard: " << wildcard << endl;

	int count = 0;

	//basecase 1 : �� �̻� wildcard�� ���ڿ��� �������� �ʴ� ���.
	if (wildcard.empty())
	{
		if (file.empty()) 		//file�� �ƹ� ���ڿ��� �������� �ʴ� ���
			return 1;
		else
			return 0;			//file�� � ���ڶ� �����ϴ� ���
	
	}




	//basecase 2 : �� �̻� file�� ���ڿ��� �������� �ʴ� ���
	if (file.empty())
	{
		//*�� ������ ���ڿ��� wildcard�� �����ϴ� ���
		//*�� ������ ���ڿ��� wildcard�� �������� �ʴ� ���.
		for (int i = 0; i < wildcard.size(); i++) {
			if (wildcard[i] != '*')
				return 0;
		}
		return 1;

	}


	//�� �κк��ʹ� �ᱹ wildcard�� file�� ���ڰ� �ϳ��� �־���� ���� �� �ִ�.

	//case 1 : '?'�� ���� ���
	//������ �б�
	if ( wildcard.front() == '?' ) {

		count+= compare(file.substr(1), wildcard.substr(1));
		if (count != 0)
			return 1;
	}
	else if (wildcard.front() == '*') {
		//case 2 : '*'�� ���� ��� -> file�� ������ ���� ��� ����� ���� ���� �غ�.
		for (int i = 0; i <= file.size(); i++) {


			count += compare(file.substr(i), wildcard.substr(1));
			if (count != 0)
				return 1;
		}


	} else {
		//case 3 : ������ ���ڿ� (����, �빮��, �ҹ��� ���� ���)
		if (file.front() == wildcard.front()) {
			count += compare(file.substr(1), wildcard.substr(1));
		}
		else
			return 0; //����
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

