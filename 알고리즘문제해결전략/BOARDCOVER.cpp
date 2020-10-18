//���� ������ ä��� �ɷ� ������ ���������ش�.

#include <iostream>
#include <algorithm>
#include <utility>


using namespace std;

int board[21][21]; //��� : 0 , ������ : 1
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


int find_all_cases(int row, int col) //row, col�� ���� ��ġ�� ����. 
{
	int count = 0; // ��� ����� ���� ��ȯ�޴´�.
 
	//ä�� �� �ִ� ����� �������� �ʴ� ��� �ű⼭ ����. return 0;
	
	//base case : ������ �ǿ� ������ ���
	if (row == H - 1 && col == W - 1) {
		
		if (board[row][col] == 1)
			return 1;
		else
			return 0;

	}

	// �ش� ĭ�� �������� ��� ���� ĭ���� ����.
	if (board[row][col] == 1)
	{
		pair<int, int> temp = find_next_idx(row,col);
		return find_all_cases(temp.first, temp.second);
	}


	//ä�� �� �ִ� ����� 4���� ��찡 ���� 
	//1 0   0 1  1 1  1 1
	//1 1   1 1  0 1  1 0
	//��� ��쿡 �غ����ϱ� ������ ������ if������ �����ؾߵȴ�.

	if (row + 1 < H && col + 1 < W) //����� ������ �Ѿ ��츦 ���ܽ����ش�.
	{
		//case 1:
		if (board[row][col] == 0 && board[row + 1][col] == 0 && board[row + 1][col + 1] == 0)
		{
			board[row][col] = 1;
			board[row + 1][col] = 1;
			board[row + 1][col + 1] = 1;
			pair<int, int> temp = find_next_idx(row, col);
			count += find_all_cases(temp.first, temp.second);
			//��ݺ��� ���� �ٽ� 0���� �ٲ��ش�.
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
			//��ݺ��� ���� �ٽ� 0���� �ٲ��ش�.
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
			//��ݺ��� ���� �ٽ� 0���� �ٲ��ش�.
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
			//��ݺ��� ���� �ٽ� 0���� �ٲ��ش�.
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
		cin >> H >> W;   //��, �� �Է¹޴´�.
		int count = 0;


		//# -> 1, . => 0���� �ʱ�ȭ�����ش�.
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char temp;
				cin >> temp;
				if (temp == '#')
					board[i][j] = 1;

				else {
					board[i][j] = 0;
					count++; //3�� ����� ��츸 �����ϱ� ������ ����ó���� ���ؼ�.
				}

			}
		}
			

		
		if (count == 0)   //��� ĭ�� �������� ���.
			cout << 1<<endl;
		else if (count % 3 != 0) //�� ĭ�� 3�� ����� �ƴ� ���.
			cout << 0<<endl;

		else { //  ���ܰ� �ƴ� �κ� -> ���ȣ���� ���� ������
			cout << find_all_cases(0, 0) <<endl;
		}


	
	}

	return 0;
}