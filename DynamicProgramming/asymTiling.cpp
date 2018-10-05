//18.10.5 , tiling2.cpp참조
#include <iostream>
using namespace std;

//홀수의 경우 n/2의 모든경우가 대칭
//짝수의 경우 n/2-1 과 n/2의 모든 경우가 대칭

int cache[101]; //cache[i] : i개의 타일을 채우는 최댓값.
int n; //갯수


int tiling(int num)
{
	int &ret = cache[num];
	
	if(ret !=-1)
		return ret;
	
	if(num == 1)
		return ret = 1;
	else if(num == 2)
		return ret = 2;
	
	return ret = (tiling(num-1) + tiling(num-2))% 1000000007;
	
	
	
}




int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		cin>>n;
		for(int i = 0 ; i<=n; i++)
			cache[i] = -1;
		
		//cout<<tiling(n)<<endl;
		
		tiling(n);
		
		int value ;
		if(n==1)
			value = 0;
		else if(n==2)
			value = 0 ;
		else if(n%2 == 1)
		{
			value = (cache[n]-cache[n/2])% 1000000007;
		}
		else
		{
			value = (cache[n]-(cache[n/2 -1] + cache[n/2])% 1000000007)% 1000000007;
		}

		if(value>=0)
			cout<<value<<endl;
		else
			cout<<1000000007+value<<endl;
	
		
		
		
	}
	
	
	
	
	
	
	return 0;
}