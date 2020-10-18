/*
18.10.10
어떻게 문제에 접근해야 할지 몰라서, 젤 처음 접근법만 참고(각 가로줄마다 몇 개의 정사각형을 넣을지를 결정하고, 왼쪽 오른쪽으로 적절히 밀어주면까지).
알고리즘은 직접 구현

N개로 만들 수 있는 경우의 수는 
	
	i = (1,N,1)에서 cache[i][N-i]의 모든 합

*/

#include <iostream>

using namespace std;

int cache[101][101]; // cache[i][j] =-1로 ㅊ기화, i : 맨 윗줄 정사각형의 갯수, j : 남은 갯수
int N;


int solve(int topNum , int remain ) //main에서 첫 topNum과 remain 반복문으로 넣어주기
{
	int & ret = cache[topNum][remain];
	
	if(ret != -1)
		return ret;
	
	if(remain == 0)
		return ret =1;
	
	ret++;
	for(int i = remain; i>0 ; i--)
	{
		ret = ((ret%10000000) +(((topNum+i-1)*solve(i, remain-i))%10000000))%10000000;
	
				
		
	}
	
	return ret;
	
	
}



int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		cin>>N;
		for(int i = 0 ; i<=N; i++)
			for(int j = 0 ; j<=N; j++)
				cache[i][j] = -1;
		
		int sum = 0;
		for(int i = 1; i<=N; i++){
			sum = ((sum%10000000)  + (solve(i, N-i)%10000000))%10000000;
		}
		
		
		
		cout<<sum<<endl;
	}
	
	
	
	
	
	
	
	
}