#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define BLACK '#'
#define WHITE '.'
#define UNDEFINED 'u'
int H,W;

bool isCover(char arr[20][20]) //WHITE가 하나라도 있으면 거짓 반환
{
	for(int i= 0; i<H; i++)   //정의되지 않은 행을 만날 때까지.
	{
		for(int j = 0;  j<W ;j++) //정의되지 않은 열을 만날 때까지.
		{
			if(arr[i][j] != BLACK)
				return false;
		}
	}
	return true;
}


int boardCover(char arr[20][20],int x = 0 , int y = 0)  //x행, y열
{
	int ret = 0;
	//마지막 인덱스에 도달할경우
	if(H-1==x && W-1==y)
	{
		if(isCover(arr))
		{
			ret++;
			return ret;
		}
		return ret;		
	
	}
	//값: BLACK인경우. 
	if(arr[x][y] == BLACK)
	{

		if(arr[x][y+1] == UNDEFINED){
			ret += boardCover(arr,x+1,0);
			return ret;
		}
		ret += boardCover(arr,x,y+1);

		return ret;
	}
	
	//값: 화이트인경우
	//4가지 L자 경우 채운 후 다음 인덱스에서 검사 (반시계방향으로 돌림)
	//case1
	
	if(arr[x][y] ==WHITE && arr[x+1][y]==WHITE && arr[x+1][y+1] ==WHITE)
	{

		arr[x][y] =BLACK;
		arr[x+1][y]=BLACK;
		arr[x+1][y+1] =BLACK;
		if(arr[x][y+1] == UNDEFINED)
			ret+=boardCover(arr,x+1,0);
		else
			ret+=boardCover(arr,x,y+1);
		
		arr[x][y] =WHITE;
		arr[x+1][y]=WHITE;
		arr[x+1][y+1] =WHITE;
	}
	//case2
	if(arr[x][y] == WHITE && arr[x+1][y-1]== WHITE && arr[x+1][y] == WHITE)
	{

		arr[x][y] =BLACK;
		arr[x+1][y-1]=BLACK;
		arr[x+1][y] =BLACK;
		if(arr[x][y+1] == UNDEFINED)
			ret+=boardCover(arr,x+1,0);
		else
			ret+=boardCover(arr,x,y+1);
		arr[x][y] =WHITE;
		arr[x+1][y-1]= WHITE;
		arr[x+1][y] =WHITE;
	}

	//case3
	if(arr[x][y] ==WHITE && arr[x][y+1]==WHITE && arr[x+1][y+1] ==WHITE)
	{

		
		arr[x][y] =BLACK;
		arr[x][y+1]=BLACK;
		arr[x+1][y+1] =BLACK;
		if(arr[x][y+1] == UNDEFINED)
			ret+=boardCover(arr,x+1,0);
		else
			ret+=boardCover(arr,x,y+1);
		arr[x][y] = WHITE;
		arr[x][y+1]= WHITE;
		arr[x+1][y+1] = WHITE;
	}
	//case4
	if(arr[x][y] == WHITE && arr[x+1][y]== WHITE && arr[x][y+1] == WHITE)
	{


		arr[x][y] = BLACK;
		arr[x+1][y]= BLACK;
		arr[x][y+1] = BLACK;
		if(arr[x][y+1] == UNDEFINED)
			ret+=boardCover(arr,x+1,0);
		else
			ret+=boardCover(arr,x,y+1);
		arr[x][y] = WHITE;
		arr[x+1][y]= WHITE;
		arr[x][y+1] = WHITE;
	}
	
	
	
	return ret;
	
}




int main()
{
	
	int testCase;
	
	cin>>testCase;
	
	while(testCase>0)
	{

		cin>>H>>W;
		char arr[20][20] ={};
		char temp;
		
		for(int i=0; i<20; i++)
			for(int j=0; j<20; j++)
				arr[i][j] =UNDEFINED;
		
		
		//게임판 만들기
		for(int i= 0; i<H; i++)
		{
			for(int j = 0; j<W; j++)
			{
				cin>>arr[i][j];
	
			}
		}

		//게임판 확인
		/*
		cout<<endl<<endl;
		for(int i= 0; i<H; i++)
		{
			for(int j = 0; j<W; j++)
			{
				cout<<arr[i][j];
	
			}
			cout<<endl;
		}
		*/
		cout<<boardCover(arr)<<endl;

		
		

		
		
		
		H=0;
		W=0;
		
		
		testCase--;
	}
	
	
	
	return 0;
}
