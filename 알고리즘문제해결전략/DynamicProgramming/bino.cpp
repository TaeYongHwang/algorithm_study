#include <iostream>
using namespace std;

//이항계수 

//(n r) = (n-1 r-1)+ (n-1 r)



//기본
int bino(int n, int r)
{
	//basecase
	if(n == 0 || r == 0)
		return 1;
	
	
	
	return bino(n-1,r-1) +bino(n-1,r);	
	
}

//meoization 이용
int cache[100][100] ;


int bino2(int n, int r)
{

	//basecase
	if(n == 0 || r == 0)
		return 1;
	
	int &ret = cache[n][r];
	
	//이미 계산한 값인지 확인
	if(ret != -1)
		return ret;
	
	
	
	return ret= bino2(n-1,r-1) + bino(n-1,r);
	
	
	
}


int main()
{
	for(int i = 0 ; i<100; i++)
		for(int j = 0 ; j<100; j++)
			cache[i][j] =-1;
	
	
	cout<<bino2(25,10);
	
	
	
	
	
	
	
	
	
}