#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


vector<pair<int, int>> mix;
vector<int> ans;
char LEFT = 'L';
char RIGHT = 'R';
int N;

bool isDeceivable(int ballLocation, char dir) {
    if(dir == 'L') {
        if(ballLocation > 1) return true;
    } else if(dir == 'R') {
        if(ballLocation < N) return true;
    }
    return false;
}

int changeBallLocation (int swap1, int swap2, int target) {
    if(swap1 == target) {
       return swap2; 
    } else if(swap2 == target) {
        return swap1;
    }
    return target;
}


void findAns(int ballLocation = 1, int count = 0, bool isAlreadyDeceived = false) {
     /** 종료 상황 **/
     if(count == mix.size()) {
         /** 속이지 않은 경우 - 1회 속여야 한다. **/
         if(!isAlreadyDeceived) {
             if(isDeceivable(ballLocation, LEFT)) {
                 if(find(ans.begin(), ans.end(), ballLocation -1) == ans.end()) {
                     ans.push_back(ballLocation -1 );
                 }
             }
             if(isDeceivable(ballLocation, RIGHT)) {
                 if(find(ans.begin(), ans.end(), ballLocation +1) == ans.end()) {
                     ans.push_back(ballLocation +1 );
                 }
             }
         } else {
             /** 이미 속인 경우 **/
                 if(find(ans.begin(), ans.end(), ballLocation) == ans.end()) {
                     ans.push_back(ballLocation);
                 }
         }
         return;
     }


     if(!isAlreadyDeceived) {
         if(isDeceivable(ballLocation, LEFT)) {
             findAns(changeBallLocation(mix[count].first, mix[count].second, ballLocation - 1), count + 1, true);
         }

         if(isDeceivable(ballLocation, RIGHT)) {
             findAns(changeBallLocation(mix[count].first, mix[count].second, ballLocation + 1), count + 1, true);
         }
     }

     findAns(changeBallLocation(mix[count].first, mix[count].second, ballLocation), count + 1 , isAlreadyDeceived);
 }


void findAns2(int deceivedIdx, char dir, int ballLocation = 1) {
    for(int i = 0 ; i < mix.size() ; i ++) {
        if(i == deceivedIdx) {
            if(dir == RIGHT) {
                if(!isDeceivable(ballLocation, RIGHT)) return;
                ballLocation = changeBallLocation(mix[i].first, mix[i].second, ballLocation + 1);
            } else {
                if(!isDeceivable(ballLocation, LEFT)) return;
                ballLocation = changeBallLocation(mix[i].first, mix[i].second, ballLocation - 1);
            }
        } else {
            ballLocation = changeBallLocation(mix[i].first, mix[i].second, ballLocation);
        }
    }

    if(deceivedIdx == mix.size()) {
        if(dir == RIGHT) {
            if(!isDeceivable(ballLocation, RIGHT)) return;
            ballLocation += 1;
        } else {
            if(!isDeceivable(ballLocation, LEFT)) return;
            ballLocation -= 1;
        }
    }

     if(find(ans.begin(), ans.end(), ballLocation) == ans.end()) {
        ans.push_back(ballLocation);
      }

}


int main() {
    int tc, count = 0;
    cin >> tc;

    while(count++ < tc) {
        int Q, src, dest;
        cin >> N >> Q;

        while(Q--) {
            cin >> src >> dest;
            mix.push_back({src, dest});
        }
        
        //findAns();

        for(int i = 0 ; i <= mix.size(); i++) {
            findAns2(i, LEFT);
            findAns2(i, RIGHT);
        }

        /*
        for(int i = 0 ; i < ans.size(); i++) {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        */

        cout<<'#'<<count<<' '<<ans.size()<<endl;

    

        mix.clear();
        ans.clear();
    }

    return 0;
}