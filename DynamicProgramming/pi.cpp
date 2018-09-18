/*18.9.18
cache[i] : i번쨰를 시작으로하는 부분스트링에서 가장 작은 난이도값을저장.

*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//int value[5] = {1,4,7,10,13};
int N;
int value[10000];
int cache[10000]; //-1로초기화



int selectCase(int startIdx, int num) //startIdx에서 num개만큼 묶였을때 난이도 반환
{
	//난이도 1---------------------
	bool case1 = true;
	for(int i =startIdx; i<startIdx+num-1; i++)
	{
		if(value[i] != value[i+1])
			case1 = false;
		
	}
	if(case1 == true)
		return 1;
	
	//난이도 2--------------------
	bool case2_desc = true;
	for(int i = startIdx; i<startIdx+num-1; i++)
	{
		if(value[i] != value[i+1]+1) //단조감소
			case2_desc =false;
		
	}
	if(case2_desc == true)
		return 2;
	bool case2_asc = true;
	for(int i = startIdx; i<startIdx+num-1; i++)
	{
		if(value[i] != value[i+1]-1) //단조증가
			case2_asc =false;
		
	}
	if(case2_asc == true)
		return 2;
	
	
	//난이도 4----------------------
	if(num == 3)
	{
		if(value[startIdx] == value[startIdx+2])
			return 4;
	}
	else if(num == 4)
	{
		if(value[startIdx] == value[startIdx+2] && value[startIdx+1] == value[startIdx+3])
			return 4;
	}
	else if(num == 5)
	{
		if(value[startIdx] == value[startIdx+2] && value[startIdx] == value[startIdx+4] && value[startIdx+1] == value[startIdx+3])
			return 4;
	}
	
	
	//난이도 5 -------------------
	bool case5 = true;
	int d = value[startIdx+1]- value[startIdx];
	
	for(int i = startIdx+1; i<startIdx+num-1; i++)
	{
		if(d != value[i+1] - value[i] )
			case5 = false;
		
		
	}	
	if(case5 == true)
		return 5;
	
	
	
	
	
	
	//난이도 10---------------------------------
	
	return 10;
	
	
}


int solve(int startIdx)
{
	//범위초과
	if(startIdx>=N)
	{
		return 100000;
	}

	int &ret = cache[startIdx];
	
	if(ret !=-1) //이미계산
		return ret;

	//basecase : 마지막 경우 (3~5개 남은 경우)
	if(startIdx+3 == N)
		return ret =selectCase(startIdx,3);
	else if(startIdx+4 == N)
		return ret =selectCase(startIdx,4);
	else if(startIdx+5 ==N)
		return ret =selectCase(startIdx,5);
	
	
	
	
	//기본계산
	int minV = 1000000;
	
	
	
	minV = min(minV, selectCase(startIdx,3) + solve(startIdx+3) );
	minV = min(minV, selectCase(startIdx,4) + solve(startIdx+4) );
	minV = min(minV, selectCase(startIdx,5) + solve(startIdx+5) );
	
	return ret = minV;
	
}








int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		string str;
		cin>>str;
		N = str.length();
		for(int i = 0 ; i<N; i++)
		{
			value[i] = str[i];
			cache[i] = -1;	
		}
		
		
		cout<<solve(0)<<endl;

		
	}
	
	
	
	
	
	return 0;
}