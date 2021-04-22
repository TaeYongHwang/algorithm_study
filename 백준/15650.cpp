#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void combination(vector<int>& cur, int limit) {
    if(cur.size() == limit) {
        for(int i = 0 ; i < cur.size() ; i++) {
            printf("%d ", cur[i]);
        }
        printf("\n");
        return;
    }

    int start = cur.size() == 0 ? 1 : cur.back() + 1;


    for(int i = start; i <= N ; i++) {
        cur.push_back(i);
        combination(cur, limit);
        cur.pop_back();
    }
}

int main() {

    cin >> N >> M;

    vector<int> tmp;
    combination(tmp, M);

}