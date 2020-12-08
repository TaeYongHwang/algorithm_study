#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

/**
 * 이진 트리의 깊이를 생각해서 풀어야 한다.
 * 1. 타켓 깊이가 홀수인 경우 : 밥은 2x+1, 엘리스는 2x 뽑는 것이 최선이다. (마지막 뽑는 사람이 엘리스이므로)
 * 
 * 2. 타겟 깊이가 짝수인 경우 : 밥은 2X, 엘리스는 2X+1 뽑는 것이 최선이다. (마지막 뽑는 사람이 밥이므로)
 * **/



int findDepth(long long targetNum) {
    int count = 0;
    while(targetNum / 2 != 0) {
        targetNum /= 2;
        count ++;
    }

    return count;
}


string findAns(long long targetNum, const int destDepth, long long retNum = 1, int curDepth = 0, string user = "Alice") {
    string otherUser = user == "Alice"? "Bob" : "Alice";

    if(destDepth == curDepth) {
        if(targetNum >= retNum) return otherUser;
        else return user;
    }

    
    
    if(destDepth %2 == 1) {
        if(user == "Alice") return findAns(targetNum, destDepth, 2 * retNum, curDepth + 1, otherUser);
        else return findAns(targetNum, destDepth, 2 * retNum + 1 , curDepth + 1, otherUser);
    } else {
        if(user == "Alice") return findAns(targetNum, destDepth, 2 * retNum + 1, curDepth + 1, otherUser);
        else return findAns(targetNum, destDepth, 2 * retNum , curDepth + 1, otherUser);    
    }

}





int main() {

    int T;
    cin >> T;

    for(int tc = 1 ; tc <=T ; tc++) {
        long long limit;
        scanf("%lld", &limit);

        if(limit == 1) printf("#%d Bob\n", tc);
        else {

            printf("#%d %s\n", tc, findAns(limit, findDepth(limit)).c_str());
            //cout<<'#'<<tc<<' '<<findAns(1, limit)<<endl;
        }

    }

}