//2018.10.12
//lis.cpp참조
//길이가 길어질 떄마다. 최대증가부분수열의 다음 숫자의 인덱스를 cache2에저장해. 더 이상
//연결되지 않을 때까지(-1을 만날떄까지) 출력
#include <iostream>
#include <algorithm>
using namespace std;

int length;
int cache[500] ; //-1로 초기화, 해당인덱스부터 시작하는 증가부분수열의 최대길이 저장
int value[500] ;
int cache2[500] ; //-1로초기화, 해당인덱스부터 시작하는 최대증가부분수열의 다음 인덱스저장
			
int LIS(int curLen = 0)
{
	int &ret = cache[curLen];
	
	//basecase
	if(curLen == length-1)
	{
		return ret = 1;
	}

	if(ret != -1)
		return ret;
	
	int maxLen = 1;
	for(int i= curLen+1; i<length; i++)
	{
		if(value[curLen] < value[i])
		{
			if(maxLen != max(maxLen, LIS(i)+1))
			{
				maxLen = LIS(i)+1;
				cache2[curLen] = i;
				
			}
		}
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
			cache2[i] = -1;
		}
		
		LIS();
		//cout<<LIS()<<endl;
		//for(int i = 0 ; i<length; i++)
		//	cout<<cache[i]<<' ';
		
		int corAns = -1;
		int idx = -1;
		for(int i = 0 ; i <length; i++)
		{
			if(corAns == max(corAns, cache[i]))
			{
				corAns = max(corAns, cache[i]);
				idx = i; 
				
			}
		}
		
		if(cache2[idx] ==-1)
			cout<<value[cache[idx]]<<endl;
		else
		{
			while(cache2[idx] != -1)
			{
				cout<<value[cache2[idx]]<<' ';
				idx = cache2[idx];	
			}
			
		}
		
		


		
		
		
//		cout<<corAns<<endl;
		
		
		
	}
	
	
	
	
	
	
	
	
	
}