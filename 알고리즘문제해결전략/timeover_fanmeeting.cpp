#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
모든 멤버가 동시에 포옹하는 경우  : 모든 쌍에 MM이 없어야 한다.
모든 멤버가 포옹하는 경우의 수를 구하라.
 F : 0, M : 1

1. 멤버 숫자만큼 멤버 초기화
2. 멤버 + 팬 숫자만큼 팬 초기화 (멤버 자리에는 F값으로, fan자리에는 성별로)
   ->빈 자리를 F값으로 초기화하는 이유 : MM을 제외한 모든 경우는 포옹이라고 생각하기때문
3. 팬을 shift operator를 이용해 계속 밀면서 모든 사람이 포옹하는지 확인.
*/

//포옹하는 경우인지 판별
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

//모든 경우에 대해서 하는 wrapper function
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