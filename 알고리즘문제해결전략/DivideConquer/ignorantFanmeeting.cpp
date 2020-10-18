#include <iostream>
#include <vector>
#include <string>
using namespace std;


int NumOfHandShake(string& member, string& fan )  // 모든 멤버가 팬과있는 상황에서 , 한명이라도 남,남 인 경우(악수하는 경우)
{
	int memNum = member.size();
	int fanNum = fan.size();
	int count = 0;
	
	for(int i = 0; i< fanNum-memNum+1; i++)
	{
		for(int j = 0 ; j<memNum; j++)
		{
			if(member[j] == 'M' && fan[j] =='M')
			{
				count++;
				break;
				
			}
			
			
				
		}
		
		fan = fan.substr(1);
		
	}
	
	
	return count;	
	
	
	
	
}


int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		string mem;
		string fan;
		
		cin>>mem>>fan;
		
		int allCase = fan.size() -mem.size()+1;
		
		
		cout<<allCase - NumOfHandShake(mem, fan)<<endl;
		
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}

