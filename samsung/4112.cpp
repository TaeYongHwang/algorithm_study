#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;



int board[200][200] = {0, };

map<int, pair<int,int>> M;

int target[6][2] = {
    {-1, -1},
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
    {1, 1},
};



void init() {
    int num = 1;

    for(int i = 1; num <= 10000 ; i++) {
        for(int j = 1 ; j <= i ; j++) {
            M.insert({num, {i, j}});
            board[i][j] = num;
            num++;
        }
    }

    /*
    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j< 10 ; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    */
}




int findAns(int src, int dest, int limit) {
    queue<pair<int,int>> Q;
    pair<int,int> destLocation = M[dest];

    Q.push({src, 0});
    
    while(!Q.empty()) {
        int curNum = Q.front().first;
        int count = Q.front().second;

        if(curNum == dest) return count;

        pair <int,int> location = M[curNum];
        Q.pop();

        pair<int,int> nextLocation;
        int minDist = 100000;

        for(int i = 0 ; i < 6 ; i++) {
        
            pair<int, int> tempLocation = {location.first + target[i][0], location.second + target[i][1] };
            int tempNum = board[tempLocation.first][tempLocation.second];

            if(tempNum > 0 && tempNum <= limit) {
                int tempDist = abs(tempLocation.first - destLocation.first) + abs(tempLocation.second - destLocation.second);
                 if( tempDist < minDist) {
                       nextLocation = tempLocation;
                      minDist = tempDist;
                }
            }


            
        }
        Q.push({board[nextLocation.first][nextLocation.second], count+1 });
    }
    return -1;
}
 


int main() {
    init();    


    int T;
    cin >> T;

    for(int tc = 1 ; tc <=T ; tc++) {
        int src, dest;
        cin >> src >> dest;

        int limit = max(src, dest);
        

        cout<<'#'<<tc<<' '<<findAns(src,dest, limit)<<endl;


    }

}