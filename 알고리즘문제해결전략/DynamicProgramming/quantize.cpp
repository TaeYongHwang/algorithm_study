/*-----
18.9.29 hithub, xodyd15@naver.com
-----*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int value[100];
int cache[100][100] ; //cache[i][j] == idx i부터 j 까지 오차제곱의 합의 최소치를 저장
int mainCache[100][11] ; //남은 조각 갯수 역시 메모이제이션해야된다. idx값으로는 부족하다.
int n;
int Num;





int minSum(int startIdx, int endIdx) //[]모양으로 전달
{
	int &ret = cache[startIdx][endIdx];
	
	if(ret!=-1)
		return ret;
	

	int mean = 0;
	for(int i = startIdx; i<=endIdx ; i++ )
		mean+=value[i];
	
	mean = floor(( (double)mean/(endIdx-startIdx+1) ) +0.5) ;
	
	int sum = 0;
	
	for(int i = startIdx; i<=endIdx ; i++)
	{
		sum+= (value[i]-mean)*(value[i]-mean);
		
	}
	
	
	return ret = sum;
}


int quantize(int startIdx = 0, int s=Num)
{
	int &ret = mainCache[startIdx][s];
	if(ret !=-1)
		return ret;
	
	
	
	if(s ==1) //마지막조각
		return minSum(startIdx, n-1);
	
	
	int minVal = 987654321;
	
	for(int i = startIdx; i<n-s+1; i++)
	{
			minVal = min(minVal, quantize(i+1,s-1) + minSum(startIdx,i));
		
	}
		
	
	
	return ret = minVal;
}









int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		cin>>n>>Num;
		for(int i = 0 ; i<n; i++)
		{
			cin>>value[i];
		
		}
		
		for(int i = 0 ; i<n; i++)
			for(int j = 0 ; j<n; j++)
				cache[i][j] = -1;
		
		for(int i = 0 ; i<n; i++)
			for(int j = 0 ; j<=Num; j++)
				mainCache[i][j] = -1;
		
		
		sort(value, value+n);
		
		
		if(Num>=n)
			cout<<0<<endl;
		else
			cout<<quantize()<<endl;


		
		
		
	
	}
	

	
	
	

		
	return 0;
}