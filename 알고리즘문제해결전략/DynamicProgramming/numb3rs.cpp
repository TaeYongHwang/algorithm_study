/*
18.10.11
참조없이 혼자 풂
*/

#include <iostream>
using namespace std;

int N, X; //N : 마을 수, X : 두니발 박사가 숨어있는 마을
int value[50][50];
double cache[51][101]; //-1로초기화, cache[i][j] : i마을에서 j일 남았을때, X마을에 갈 확률


double solve(int village, int day)
{
	double & ret = cache[village][day];
	
	if(ret != -1)
		return ret;
	
	double cnt = 0;
	if(day == 1)
	{
		//현재 마을에서 x마을로 갈 확률?
		if(value[village][X] == 1) //가는 길이 있는 경우
		{
		
			for(int i = 0 ; i<N; i++)
				if(value[village][i] == 1)
					cnt++;
			return ret = 1/cnt;
							
		}
		else
			return ret = 0;
	
		
	}
	
	ret = 0;
	
	for(int i = 0 ; i<N; i++)
			if(value[village][i] == 1)
					cnt++;
	
	for(int i = 0 ; i<N; i++)
	{
		if(value[village][i] == 1)
		{
			ret += (1/cnt) * solve(i,day-1); 
			
		}
		
	}
	
	
	
	
	return ret;
}


int main()
{
	cout<<fixed;
	cout.precision(8);
	int C;
	cin>>C;
	while(C--)
	{
		int day, startIdx;
		int endNum;
		cin>>N>>day>>startIdx;
		
		for(int i = 0; i<N; i++)
			for(int j = 0 ; j<N; j++)
				cin>>value[i][j];
		

		
		cin>>endNum;
		
		while(endNum --)
		{
			for(int i = 0; i<=N; i++)
				for(int j = 0 ; j<=day; j++)
					cache[i][j] = -1;
			
			cin>>X;
			cout<<solve(startIdx, day)<<' ';
			
			
		}
			
		
		
		cout<<endl;
		
		
	}
	
	
	
}











