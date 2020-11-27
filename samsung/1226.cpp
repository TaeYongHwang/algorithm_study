#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int board[16][16];
bool pass[16][16];

int LEFT = 1, UP = 2, RIGHT = 3, DOWN = 4;

int dirArr[4][3] = {
    {LEFT, 0, -1},
    {UP, -1, 0},
    {RIGHT, 0 , 1},
    {DOWN, 1, 0},
};

pair<int,int> startPos, endPos;
const int boardSize = 16;





bool isPossibleRoute() {
    queue<pair<int,int>> Q;

    Q.push(startPos);

    while(!Q.empty()) {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        pass[row][col] = true;

        if(row == endPos.first && col == endPos.second) return true;

        for(int i = 0 ; i < 4 ; i ++) {
            int nextRow = row + dirArr[i][1];
            int nextCol = col + dirArr[i][2];

            if(nextRow < 0 || nextRow >= boardSize || nextCol < 0 || nextCol >= boardSize) continue;

            if(board[nextRow][nextCol] == 3) return true;

            if(board[nextRow][nextCol] == 0 && !pass[nextRow][nextCol]) {
                Q.push({nextRow, nextCol});
            }
        }
    }

    return false;

}




int main() {

    for(int tc = 1 ; tc <= 10; tc++) {
        int trash;
        cin >>trash;

        for(int i = 0 ; i < boardSize ; i++) {
            for(int j = 0 ; j < boardSize ; j++) {
                char temp;
                cin >>temp;
                int tempToInt = temp - '0';
                
                board[i][j] = tempToInt;
                pass[i][j] = false;
                if(board[i][j] ==2) {
                    startPos = {i, j};
                } else if (board[i][j] == 3) {
                    endPos = {i, j};
                }
            }
        }

        cout<<'#'<<tc<<' '<<isPossibleRoute()? 1 : 0;
        cout<<endl;

    }




}
