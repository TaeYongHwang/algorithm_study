#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
//성공한 경우가 있을때 성공하는 문제이기떄문에
//실패한 경우 (범위 밖으로 나가는 경우)역시 메모이제이션해야한다.
//그래서 bool이 아닌 int값으로 캐쉬를 구성한다.
// -1 : 계산 x, 0 : 실패 , 1 : 성공
//1번이라도 지나갔는지 안지나갔는지 판별하는 것이 동적계획법이 핵심인듯!

int n;
int cache[100][100]; // false로초기화
int arr[100][100];

//[0, n)
int jumpgame(int y, int x)
{
	//basecase 1: 범위초과
	if(y>=n || x>=n)
		return 0;
	//basecase 2: 끝에 도달.
	if(y == n-1 && x == n-1)
		return 1;
	
	int &ret = cache[y][x];

	//이미 한 번 계산한 경우
	if(ret != -1)
		return ret;
	
	
	//한번도 계산하지 않은 경우
	return ret = jumpgame(y+arr[y][x],x) || jumpgame(y,x+arr[y][x]);

	

}


int main()
{
	int C;
	
	cin>>C;
	while(C--)
	{
		int temp;
		cin>>n;
		
		for(int i = 0 ; i<n ; i++){
			for(int j = 0; j<n; j++){
				scanf("%d", &arr[i][j]);
				cache[i][j] = -1;
			}
			
		}
		
		
		if(jumpgame(0,0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
	
}


