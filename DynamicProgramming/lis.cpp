#include <iostream>
#include <algorithm>
using namespace std;

int length;
int cache[500] ; //-1로 초기화, 해당인덱스부터 시작하는 증가부분수열의 최대길이 저장
int value[500] ;


int LIS(int curLen = 0)
{
	int &ret = cache[curLen];
	
	//basecase
	if(curLen == length-1)
		return ret = 1;
	

	if(ret != -1)
		return ret;
	
	int maxLen = 1;
	for(int i= curLen+1; i<length; i++)
	{
		if(value[curLen] < value[i])
			maxLen = max(maxLen, LIS(i)+1);
		else
			LIS(i);
	}
	
	return ret = maxLen;
	
}


int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		cin>> length;
		
		for(int i = 0; i<length; i++)
		{
			cin>>value[i];
			cache[i] = -1;
			
		}
		
		LIS();
		//cout<<LIS()<<endl;
		//for(int i = 0 ; i<length; i++)
		//	cout<<cache[i]<<' ';
		
		int corAns = -1;
		for(int i = 0 ; i <length; i++)
		{
			corAns = max(corAns, cache[i]);
		}
		
		cout<<corAns<<endl;
		
		
		
	}
	
	
	
	
	
	
	
	
	
}