//18.10.1
#include <iostream>
using namespace std;

int cache[100]; //cache[i] : i번쨰 열에서 시작할 때의 타일 채우는 방법의 최대값.
int n; //갯수


int tiling(int idx)
{
	int &ret = cache[idx];
	
	if(ret !=-1)
		return ret;
	
	if(idx ==n-1)
		return ret = 1;
	else if(idx == n-2)
		return ret = 2;
	
	return ret = (tiling(idx+1) + tiling(idx+2))% 1000000007;
	
	
	
}

int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		cin>>n;
		for(int i = 0 ; i<n; i++)
			cache[i] = -1;
		
		cout<<tiling(0)<<endl;
		
		
		
		
		
		
	}
	
	
	
	
	
	
	return 0;
}