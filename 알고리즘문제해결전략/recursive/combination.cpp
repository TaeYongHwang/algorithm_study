#include <vector>
#include <iostream>
using namespace std;

vector<int> v;
vector<int> picked;
void combination(vector<int>& v, int allNum, int pickNum)
{
	if(pickNum == 0) //다뽑은 경우 출력
	{
		for(int i = 0 ; i< picked.size(); i++)
			cout<<picked[i];
		cout<<endl;
	
		return ;
	}
	
	int smallest = picked.empty() ? 0: picked.back()+1;
	for(int next = smallest; next< allNum ; next++)
	{
		picked.push_back(next);
		combination(v, allNum, pickNum-1);
		picked.pop_back();
	}
	
	
}

int main()
{
	for(int i = 0 ; i<5; i++)
		v.push_back(i);
	
	combination(v, 5, 3);
	
	return 0;
	
	
}