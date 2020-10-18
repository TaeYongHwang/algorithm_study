/*--------------------
18.8.30
dynamic programming 이용.
-------------------*/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;



int N; 
int cache[100][100]; //-1로 초기화 남은 최대거리를 저장 즉 cache[0][0]에 전체문제의  최대거리가 저장됨.
int value[100][100]; //삼각형 값저장.


int find(int y = 0, int x = 0)
{

	//basecase
	if(y == N-1) //마지막줄 도달한경우
	{

		return value[y][x];
	}
	
	
	int &ret = cache[y][x];
	if(ret != -1) //이미 최대거리가 저장된경우
	{
		return ret;
	}
	

	//아직 cache에 값저장이 안된 경우
	return ret = (find(y+1,x)  > find(y+1, x+1) ? find(y+1,x) : find(y+1,x+1)) + value[y][x];  
	
	
}


int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		cin>>N;
		for(int i = 0 ; i<N; i++)
		{
			for(int j = 0 ; j<=i; j++ )
			{
				cache[i][j] = -1;
				scanf("%d", &value[i][j]);
	
			}
		}
		
		
		cout<<find()<<endl;
		
	
		
		
	}
	
}


