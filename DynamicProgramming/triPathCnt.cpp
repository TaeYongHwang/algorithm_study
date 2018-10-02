/*--------------------
18.10.2
trianglePath.cpp 이용
-------------------*/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;



int N; 
int cache[100][100]; //-1로 초기화 남은 최대거리를 저장 즉 cache[0][0]에 전체문제의  최대거리가 저장됨.
int value[100][100]; //삼각형 값저장.
int cache2[100][100]; //-1로 초기화, 해당 인덱스에서의 최대거리의 개수를 저장.

int find(int y = 0, int x = 0)
{

	int &ret = cache[y][x];
	//basecase
	if(y == N-1) //마지막줄 도달한경우
	{

		return ret = value[y][x];
	}
	
	
	
	if(ret != -1) //이미 최대거리가 저장된경우
	{
		return ret;
	}
	

	//아직 cache에 값저장이 안된 경우
	return ret = (find(y+1,x)  > find(y+1, x+1) ? find(y+1,x) : find(y+1,x+1)) + value[y][x];  
	
	
}

int solve(int y = 0 , int x = 0)
{
	int &ret = cache2[y][x];
	
	if(ret !=-1)
		return ret;
	
	if(y ==N-1)
		return ret = 1;
	
	
	
	if(cache[y+1][x] == cache[y+1][x+1])
		return ret = solve(y+1, x) + solve(y+1,x+1);
	else
		return ret = (cache[y+1][x] > cache[y+1][x+1] ? solve(y+1,x) : solve(y+1,x+1)); 
	
	
	
	
	
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
				cache2[i][j] = -1;
				scanf("%d", &value[i][j]);
	
			}
		}
		
		find();
		//solve();
		cout<<solve()<<endl;
		/*
		for(int i = 0 ; i<N; i++)
		{
			for(int j = 0 ; j<=i; j++ )
			{
				cout<<cache2[i][j]<<' ';
	
			}
			cout<<endl;
		}
		*/
		
		
	}
	
}


