#include <iostream>
#include <map>
#include <string>

using namespace std;

const int LEFT = 1, UP = 2, RIGHT = 3, DOWN = 4; 
int board[4][4];



bool movable(int row, int col, int dir) {
    switch(dir) {
        case LEFT :
            if(col == 0) return false;
            break;

        case UP :
            if(row == 0) return false;
            break;
        
        case RIGHT :
            if(col == 3) return false;
            break;

        case DOWN:
            if(row == 3) return false;
            break; 
    }
    return true;
}


void findAns(int row, int col, map<string, int>& m, string& str, int count = 0) {
    if(count == 7) {
        if(m.find(str) == m.end()) {
            m.insert({str, true});
        }
        return;
    };

    // cout<< count<<endl;

    if(movable(row, col, LEFT)) {
        str.push_back(board[row][col]);
        findAns(row, col-1, m, str, count+1);
        str.pop_back();
    }

    if(movable(row, col, UP)) {
        str.push_back(board[row][col]);
        findAns(row -1 , col, m, str, count+1);
        str.pop_back();
    }

    if(movable(row, col, RIGHT)) {
        str.push_back(board[row][col]);
        findAns(row, col+1, m, str, count+1);
        str.pop_back();
    }

    if(movable(row, col, DOWN)) {
        str.push_back(board[row][col]);
        findAns(row + 1, col, m, str, count+1);
        str.pop_back();
    }
    return;
}





int main() {
    int tc;

    cin>> tc;

    for(int count = 1 ; count <= tc ; count++) {
    
        for(int i = 0 ; i <4; i++) {
            for(int j = 0 ; j <4 ; j ++) {
                cin >> board[i][j];
            }
        }
        map<string, int> m;

        for(int i = 0 ; i <4; i++) {
            for(int j = 0 ; j <4 ; j ++) {
                string str = "";
                findAns(i, j, m, str, 0);
            }
        }
        
        cout<<'#'<<count<<' '<<m.size()<<endl;


        
    }







}