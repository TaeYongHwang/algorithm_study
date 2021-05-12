#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// N, M
// [1,N] 중에 중복 없이 M개를 고른 수열 (사전 순으로 증가하는 순서)

int N, M;
vector<bool> isUsed;

void combination(vector<int>& cur, int count, int limit) {
    if(cur.size() == limit) {
        //정답
        for(int i = 0 ; i < cur.size() ; i++) {
            printf("%d ", cur[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1 ; i <= N ; i++) {

        if(isUsed[i]) continue;

        cur.push_back(i);
        isUsed[i] = true;
        combination(cur, count + 1, limit);
        isUsed[i] = false;
        cur.pop_back();
    }
}

int main() {
    cin>> N >> M;
    vector<int> tmp;
    isUsed = vector<bool>(N + 1 , false);
    combination(tmp, 0, M);
}