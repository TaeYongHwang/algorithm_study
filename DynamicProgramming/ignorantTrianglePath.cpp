/*-----------------------
2018.8.29 (완전탐색)  --> 입력이 커지면 감당을 못한다..
queue를 사용했음
-------------------------*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N; //개수

int cache[101][101]; //-1로 초기화.
int value[101][101]; //각 위치의 값

queue< pair<int,int> > q; //queue에 좌표저장. //first = 행, second = 열
						  //젤 처음값 삽입 후 시작.

int maxVal()
{
	vector<int> v;
	for(int i = 0 ; i<N; i++)
		v.push_back(cache[N-1][i]);
	
	sort(v.begin(), v.end()); //오름차순
	return v[N-1];
	
}



int find()
{
	q.push(pair<int,int>(0,0));
	cache[0][0] = value[0][0];

	while(q.front().first != N-1)
	{	
		
		pair<int,int> idx = q.front();
		q.pop();	
		int y = idx.first;
		int x = idx.second;
		
		
		
		cache[y+1][x] = (cache[y][x] + value[y+1][x]> cache[y+1][x] ? cache[y][x] + value[y+1][x] : cache[y+1][x]);
		cache[y+1][x+1] = (cache[y][x] + value[y+1][x+1] > cache[y+1][x+1] ?  cache[y][x] + value[y+1][x+1] : cache[y+1][x+1]);
		
		
		q.push(pair<int,int>(y+1,x));
		q.push(pair<int,int>(y+1,x+1));
		
	}

	while(!q.empty())
	{q.pop();}
	

	
	return maxVal();
	
	
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
				//scanf("%d", &value[i][j]);
				value[i][j] = 10;
			}
		}
		
		
		cout<<find()<<endl;
		
	
		
		
	}
	
}











