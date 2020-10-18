#include <iostream>
#include <vector>
using namespace std;
//18.10.1
/*항상 같은 크기의 상자를 사용하고, 왼쪽 위부터 채운다고 가정한다.
그러면 가로로 상자를 채우는 경우에는 무조건 
	--
	--
	형태로 만들어진다.
세로로 상자를 채우는 경우에는 
	-
	-
	형태로 되므로

모든 경우에 블록을 만드는 형태가 강제된다.

일단 완전탐색으로 구현시.

-->이걸로 DP이용한다.(tiling2.cpp)
*/



void tiling(int row, int col, bool direction, bool on, vector <vector<int> > &v) //direction true : 가로, false : 세로  , on true :생성, false : 소거
{
	if(on == true)
	{
		if(direction == true)
		{
			v[row][col] = 1;
			v[row][col+1] = 1;
			v[row+1][col] = 1;
			v[row+1][col+1] = 1;


		}
		else
		{
			v[row][col] = 1;
			v[row+1][col] = 1;
		}
	}
	else
	{
		if(direction == true)
		{
			v[row][col] = 0;
			v[row][col+1] = 0;
			v[row+1][col] = 0;
			v[row+1][col+1] = 0;
			

		}
		else
		{
			v[row][col] = 0;
			v[row+1][col] = 0;
		}
		
	}

	
}


int n;
int totalsum = 0;
int solve(int row , int col  , vector <vector<int> > &v ) //[0,0]에서 시작
{
		
	if(v[1][n-1] == 1)
	{
		totalsum++;
		return 1;
	}
	
	int sum =0;
	if(col>=v[0].size()  ) //범위초과
		return 0;
	

	
	//가로로 채우는 경우
	if(col+1<v[0].size() && row == 0)
	{
		
	tiling(row,col,true,true,v);	
	sum+=solve( row, col+2, v);
	tiling(row,col,true,false,v);
	}
	
	//세로로 채우는 경우
	if(row == 0)
	{
		tiling(row,col,false,true,v);
		sum +=solve(row,col+1,v);
		tiling(row,col,false,false,v);
	}
	
	return sum;
	
}







int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		cin>>n;
		vector <vector <int> > v( 2, vector<int>(n,0));
		cout<<solve(0,0,v)%1000000007<<endl;
		cout<<totalsum%1000000007;
		
		totalsum = 0;
		
		vector <vector <int> >().swap(v);
		
		
		
			
	}
	
	
	
	

	
	
	
	
	
	
	
	return 0;
}






