//18.10.2 

#include <iostream>
#include <vector>
using namespace std;

double cache[1000][2001]; 
int N,M; // N미터높이, M일


double climb(int day = 0, int curHeight = 0)
{
	if(day == M)
		return curHeight>=N ? 1:0;
	
	double &ret = cache[day][curHeight];
	
	if(ret !=-1)
		return ret;
	
	
	return ret = 0.25*climb(day+1, curHeight+1) + 0.75*climb(day+1, curHeight+2);
	
	
}




int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		cin>>N>>M;
		for(int i = 0 ; i<M; i++)
		{
			for(int j = 0 ; j<(2*N+1); j++)
			{
				cache[i][j] = -1;
			}
		}
		
		 cout.precision(8);
		cout<<climb()<<endl;
		

		
		
		
		
		
	}
	
	
	
	
	
	
}

