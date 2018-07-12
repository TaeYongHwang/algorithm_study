#include <iostream>
#include <vector>
using namespace std;

//주어진 칸 덮는 4가지 방법
//상대적 위치(dy,dx) //y : 행, x:열
const int coverType[4][3][2] =
{
{{0,0}, {1,0}, {0,1}},
{{0,0}, {0,1}, {1,1}},
{{0,0}, {1,0}, {1,1}},
{{0,0}, {1,0}, {1,-1}}
};

//board (y,x)를type번 방법으로 덮거나 (delta ==1 일 때) , 덮었던 블록을 없앤다.(delta == -1일 때)
bool set(vector<vector<int> >& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for(int i = 0 ; i<3; i++)
	{
		const int ny = y+coverType[type][i][0];
		const int nx = x+coverType[type][i][1];
		if(ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size())  //보드판의 바깥값에 접근하려는경우
			ok = false;
		else if( (board[ny][nx]+= delta)>1) //두 번 덮인 경우
			ok = false;
	}
	
	return ok;	
}

//board의 모든 빈 칸을 덮을 수 있는 방법의 수 반환
//board[i][j] ==1  :이미 덮인 칸 or 검은 칸
//board[i][j] ==0  :아직 덮이지 않은 칸.
int num =1;
int cover(vector<vector<int> >& board)
{

	//가장 윗줄 왼쪽 칸은 찾는다.
	int y= -1, x=-1;
	for(int i = 0; i<board.size(); i++)
	{
		for(int j = 0; j<board[i].size(); j++)
			if(board[i][j] ==0){
				y = i ;
				x = j;
				break;
			}
		if(y !=-1) break;
	}
	//모든 칸을 채우면 1을 반환.
	
	if ( y == -1) return 1;
	int  ret =0;
	for(int type = 0 ;  type < 4; type++)
	{
		if(set(board, y, x, type, 1)){
			ret += cover(board);
		}
		
		set(board,y,x,type,-1);
	}
	
	
	return ret;
	
}


int main()
{

	int testcase;
	int H,W;
	char temp;
	vector<vector<int> > board(0, vector<int>(0));
	cin>>testcase;
	
	while(testcase>0)
	{
		int hwiteNum = 0;

		cin>>H>>W;
		board.resize(H);  //resize는 이것만, board[i]는 하면 안된다.!
		for(int i = 0; i<H; i++)
		{
			for(int j =0; j<W; j++)
			{

				cin>>temp;
				if(temp =='#')
					board[i].push_back(1);
				else{
					board[i].push_back(0);
					hwiteNum++;
				}
			}
				
		
		}


		
		//cout<<board.size()<<' '<<board[0].size()<<endl;
		
		int value = 0;
		if(hwiteNum%3 ==0)
			value =	cover(board);
		
		
		
		cout<<value<<endl;
		
		for(int i = 0 ;i<H; i++)
			board[i].clear();
		board.clear();
		
		testcase--;
	}

	
	
	return 0;
}