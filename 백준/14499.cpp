#include <iostream>
#include <vector>

using namespace std;

int N, M; //row,col
vector<vector<int>> v;

typedef struct dice {
	int left, right, up, down, front, back;
	int row, col;

	dice(int row, int col) {
		left = 0;
		right = 0;
		up = 0;
		down = 0;
		front = 0;
		back = 0;
		this->row = row;
		this->col = col;
	}

	void move(int dir) {
	
		//1 : µ¿, 2 : ¼­, 3 : ºÏ, 4 : ³²
		if (dir == 1) {
			if (col + 1 == M)
				return;

			int tmp = right;
			right = up;
			up = left;
			left = down;
			down = tmp;
			col++;
		}
		else if (dir == 2) {
			if (col - 1 < 0)
				return;
				
			int tmp = left ;
			left = up;
			up = right;
			right = down;
			down = tmp;
			col--;
		}
		else if (dir == 3) {
			if (row - 1 < 0)
				return;
			int tmp =back;
			back = up;
			up = front;
			front = down;
			down = tmp;
			row--;
		}
		else {
			if (row + 1 == N)
				return;
			int tmp =  front;
			front = up;
			up = back;
			back = down;
			down = tmp;
			row++;
		}
		cout << this->up << endl;

		if (v[row][col] == 0) {
			v[row][col] = down;
		}
		else {
			down = v[row][col];
			v[row][col] = 0;
		}

	}

} Dice;


int main() {
	int row, col, K;
	cin >> N >> M>> row>> col>>K;
	v = vector<vector<int>>(N, vector<int>());

	Dice d = Dice(row, col);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	
	while (K--) {
		int dir;
		cin >> dir;
		d.move(dir);
		
	}




}