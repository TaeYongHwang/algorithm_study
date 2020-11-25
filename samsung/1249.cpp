#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int boardSize;
vector<string> board;


const int LEFT = 1, UP = 2, RIGHT = 3, DOWN = 4;

int dirArr[4][3] =
{
    {LEFT, 0 , -1},
    {UP, -1, 0},
    {RIGHT, 0, 1},
    {DOWN, 1, 0},
};

bool isMovable(int row, int col, int dir) {
    
    switch(dir) {
        case LEFT:
            if(col > 0) return true;
            break;
        
        case RIGHT:
            if(col < boardSize - 1) return true;
            break;

        case UP:
            if(row > 0) return true;
            break;

        case DOWN:
            if(row < boardSize - 1) return true;
            break;
    }

    return false;
}





int findAns(int row = 0, int col = 0) {
    queue<pair<int,int>> Q;
    vector<vector<int>> minTime = vector<vector<int>>(boardSize, vector<int>(boardSize, -1));
    
    Q.push({row, col});
    minTime[0][0] = board[0][0] - '0';

    while(!Q.empty()) {
        pair<int,int> curLocation = Q.front();
        const int curRow = curLocation.first;
        const int curCol = curLocation.second;
        Q.pop();

    
        for(int i = 0 ; i < 4 ; i ++) {
                        
            if(isMovable(curRow, curCol, dirArr[i][0])) {
                int nextRow = curRow + dirArr[i][1];
                int nextCol = curCol + dirArr[i][2];

                //한 번도 접근 x
                if(minTime[nextRow][nextCol] == -1) {
                    minTime[nextRow][nextCol] = minTime[curRow][curCol] + + board[nextRow][nextCol] - '0';
                    Q.push({nextRow, nextCol});
                }

                //한 번 이상 접근한 경우에 값이 작아지는 경우가 들어온다면
                if(minTime[curRow][curCol] + board[nextRow][nextCol] - '0' < minTime[nextRow][nextCol]) {
                    minTime[nextRow][nextCol] = minTime[curRow][curCol] + board[nextRow][nextCol] - '0';
                    Q.push({nextRow, nextCol});
                }
            }
        }
    }
    

    return minTime[boardSize-1][boardSize-1];
}




int main() {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        board.clear();
        cin >> boardSize;

        for(int i = 0 ; i <boardSize ; i ++) {
            string temp;
            cin >> temp;
            board.push_back(temp);
        }



        cout<<'#'<<tc<<' '<<findAns()<<endl;

    }



}