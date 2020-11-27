#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int boardSize;
vector<vector<int>> board; // 0 : 클릭 x ,  1 : 클릭 o, -1 : 지뢰  

bool isNoMinesAroundPos(int row, int col) {
    for(int i = row - 1 ; i <= row +1 ; i++) {
        for(int j = col -1 ; j <= col+1 ; j++) {
            if(i < 0 || i >= boardSize || j < 0 || j >= boardSize) continue;
            if(row == i && col == j) continue;

            if(board[i][j] == -1) return false;
        }
    } 
    return true;
}

void spread(int row, int col) {

    board[row][col] = 1;

    for(int i = row - 1 ; i <= row +1 ; i++) {
        for(int j = col -1 ; j <= col+1 ; j++) {
            if(i < 0 || i >= boardSize || j < 0 || j >= boardSize) continue;

            if(board[i][j] == 0) {
                board[i][j] = 1;
                if(isNoMinesAroundPos(i,j)) {
                    spread(i, j);
                }
            }
        }
    }

}


int findAns() {
    int count = 0;
    for(int i = 0 ; i < boardSize ; i++) {
        for(int j = 0 ; j < boardSize ; j++) {
            if(board[i][j] == -1 || board[i][j] == 1) continue;

            if(isNoMinesAroundPos(i,j)) {
                spread(i,j);
                count++;
            }
        }
    }

    for(int i = 0 ; i < boardSize ; i++) {
        for(int j = 0 ; j < boardSize ; j++) {
            if(board[i][j] == 0) {
                board[i][j] = 1;
                count++;
            }
        }
    }

    return count;
}






int main() {
    int T;
    cin >> T;

    for(int tc = 1 ; tc  <= T ; tc++) {
        cin >> boardSize;

        board = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));

        for(int i = 0 ; i < boardSize ; i++) {
            for(int j = 0 ; j < boardSize ; j++) {
                char tmp;
                cin >> tmp;

                if(tmp == '.') {
                    board[i][j] = 0;
                } else {
                    board[i][j] = -1;
                }
                
            }
        }

        cout<<'#'<<tc<<' '<<findAns()<<endl;




    }


}