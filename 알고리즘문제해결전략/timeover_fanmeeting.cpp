#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
��� ����� ���ÿ� �����ϴ� ���  : ��� �ֿ� MM�� ����� �Ѵ�.
��� ����� �����ϴ� ����� ���� ���϶�.
 F : 0, M : 1

1. ��� ���ڸ�ŭ ��� �ʱ�ȭ
2. ��� + �� ���ڸ�ŭ �� �ʱ�ȭ (��� �ڸ����� F������, fan�ڸ����� ������)
   ->�� �ڸ��� F������ �ʱ�ȭ�ϴ� ���� : MM�� ������ ��� ���� �����̶�� �����ϱ⶧��
3. ���� shift operator�� �̿��� ��� �и鼭 ��� ����� �����ϴ��� Ȯ��.
*/

//�����ϴ� ������� �Ǻ�
bool is_all_hug(string member, string fan)
{
	for (int i = 0; i < member.size(); i++) {
		if (fan[i] == 'N')
			return false;

		if (member[i] == 'M' && fan[i] == 'M')
			return false;

	}
	return true;

}

//��� ��쿡 ���ؼ� �ϴ� wrapper function
int find_all_hug(string member, string fan)
{
	int sum = 0;

	while (fan[0] != 'N')
	{
		if (is_all_hug(member, fan))
			sum++;
		fan = fan.substr(1);
	}

	return sum;
}





int main()
{
	int C;

	cin >> C;
	while (C--)
	{
		string member, temp ,fan ="";
		cin >> member >> fan;

		fan += "N";
		
		cout << find_all_hug(member, fan) << endl;
		




	}
	


	return 0;
}