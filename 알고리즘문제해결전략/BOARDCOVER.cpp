//왼쪽 위부터 채우는 걸로 순서를 강제시켜준다.

#include <iostream>
#include <algorithm>
#include <utility>


using namespace std;

int board[21][21]; //흰색 : 0 , 검은색 : 1
int H, W;

pair<int, int> find_next_idx(int row, int col)
{
	if (col + 1 == W) {
		row++;
		col = 0;
	}
	else
		col++;

	return make_pair(row, col);
}


int find_all_cases(int row, int col) //row, col은 현재 위치를 기준. 
{
	int count = 0; // 모든 경우의 수를 반환받는다.
 
	//채울 수 있는 방법이 존재하지 않는 경우 거기서 종료. return 0;
	
	//base case : 마지막 판에 도달한 경우
	if (row == H - 1 && col == W - 1) {
		
		if (board[row][col] == 1)
			return 1;
		else
			return 0;

	}

	// 해당 칸이 검은색인 경우 다음 칸으로 전진.
	if (board[row][col] == 1)
	{
		pair<int, int> temp = find_next_idx(row,col);
		return find_all_cases(temp.first, temp.second);
	}


	//채울 수 있는 모양은 4가지 경우가 존재 
	//1 0   0 1  1 1  1 1
	//1 1   1 1  0 1  1 0
	//모든 경우에 해봐야하기 때문에 각각의 if문으로 구성해야된다.

	if (row + 1 < H && col + 1 < W) //블록판 범위를 넘어간 경우를 제외시켜준다.
	{
		//case 1:
		if (board[row][col] == 0 && board[row + 1][col] == 0 && board[row + 1][col + 1] == 0)
		{
			board[row][col] = 1;
			board[row + 1][col] = 1;
			board[row + 1][col + 1] = 1;
			pair<int, int> temp = find_next_idx(row, col);
			count += find_all_cases(temp.first, temp.second);
			//재반복을 위해 다시 0으로 바꿔준다.
			board[row][col] = 0;
			board[row + 1][col] = 0;
			board[row + 1][col + 1] = 0;

		}
		
		//case 3:
		if (board[row][col] == 0 && board[row][col + 1] == 0 && board[row + 1][col + 1] == 0)
		{
			board[row][col] = 1;
			board[row][col+1] = 1;
			board[row + 1][col + 1] = 1;
			pair<int, int> temp = find_next_idx(row, col);
			count += find_all_cases(temp.first, temp.second);
			//재반복을 위해 다시 0으로 바꿔준다.
			board[row][col] = 0;
			board[row][col + 1] = 0;
			board[row + 1][col + 1] = 0;
		}

		//case 4 :
		if (board[row][col] == 0 && board[row][col + 1] == 0 && board[row + 1][col] == 0)
		{
			board[row][col] = 1;
			board[row][col + 1] = 1;
			board[row + 1][col] = 1;
			pair<int, int> temp = find_next_idx(row, col);
			count += find_all_cases(temp.first, temp.second);
			//재반복을 위해 다시 0으로 바꿔준다.
			board[row][col] = 0;
			board[row][col + 1] = 0;
			board[row + 1][col] = 0;
		}
	}

	// case 2:
	if (row + 1 < H && col - 1 >= 0)
	{
		if (board[row][col] == 0 && board[row + 1][col] == 0 && board[row + 1][col - 1] == 0)
		{
			board[row][col] = 1;
			board[row+1][col] = 1;
			board[row + 1][col -1] = 1;
			pair<int, int> temp = find_next_idx(row, col);
			count += find_all_cases(temp.first, temp.second);
			//재반복을 위해 다시 0으로 바꿔준다.
			board[row][col] = 0;
			board[row + 1][col] = 0;
			board[row + 1][col - 1] = 0;

		}
	}
	
	return count;

}







int main()
{
	int C;
	cin >> C;

	while (C--) {
		cin >> H >> W;   //행, 열 입력받는다.
		int count = 0;


		//# -> 1, . => 0으로 초기화시켜준다.
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char temp;
				cin >> temp;
				if (temp == '#')
					board[i][j] = 1;

				else {
					board[i][j] = 0;
					count++; //3의 배수인 경우만 가능하기 때문에 예외처리를 위해서.
				}

			}
		}
			

		
		if (count == 0)   //모든 칸이 검정색인 경우.
			cout << 1<<endl;
		else if (count % 3 != 0) //흰 칸이 3의 배수가 아닌 경우.
			cout << 0<<endl;

		else { //  예외가 아닌 부분 -> 재귀호출을 통한 값도출
			cout << find_all_cases(0, 0) <<endl;
		}


	
	}

	return 0;
}