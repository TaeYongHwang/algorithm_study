#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;



int main() {
    int N, M;
    cin>> N >> M;

    vector<int> accumulated;

    accumulated.push_back(0);
    for(int i = 0 ; i < N ; i++) {
        int tmp;
        scanf("%d", &tmp);
        accumulated.push_back(tmp);
    }

    for(int i = 1 ; i < N ; i++) {
        accumulated[i] += accumulated[i-1];
    }

    for(int i = 0 ; i < M ; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        printf("%d\n", accumulated[end] - accumulated[start-1]);



    }



}
