//2018.10.21
//종만북 참조를 많이 했다. 아직 생각이 미치질 못하는듯.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


vector<string> vec;

int N,W;
string s[100];
int volume[100]; //부피
int need[100]; //절박도
int cache[1001][101];  //cache[i][j]용량이 i, idx가 j에 도달한 경우의 절박도의 최댓값 (j이전의 값들은 이미 챙겼는지 안챙겼는지 정해짐을 가정)


int solve(int v, int idx= 0)  
{
	int &ret = cache[v][idx];
	
	if(ret != -1)
		return ret;
	
	if( idx == N )
		return ret = 0;

	
	ret = max(ret, solve(v,idx+1)); //안담은경우
	//담은경우
	if(v-volume[idx] >=0)
		ret = max(ret, need[idx] + solve(v-volume[idx],  idx+1));

	
	return ret;
}

void reconstruct(int v, int idx= 0)
{
	if(idx ==N )
		return ;
	
	
	if(cache[v][idx] != cache[v][idx+1] &&  (cache[v][idx] !=-1 && cache[v][idx+1] !=-1))
	{
		vec.push_back(s[idx]);
		if(v-volume[idx] >=0)
			reconstruct(v-volume[idx], idx+1);
	}
	else
		reconstruct(v, idx+1);	
	
	
}



int main()
{
	int C ;
	cin>> C;
	
	while(C--)
	{
		
		cin>>N>>W;

		for(int i= 0 ; i<N; i++)
		{
			cin>>s[i]>>volume[i]>>need[i];
		}		
		for(int i = 0 ; i<=N; i++)
			for(int j = 0 ; j<=W; j++)
				cache[j][i] = -1;
		
			
		cout<<solve(W)<<' ';
		reconstruct(W);
		cout<<vec.size()<<endl;
		for(int i = 0 ; i<vec.size(); i++)
			cout<<vec[i]<<endl;
		
		
		vec.clear();
		
	}
	
	
	
	
	
	
	
	return 0;
	
	
}







