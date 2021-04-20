#include <algorithm>
#include <vector>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


// 1의 idx 저장
vector<int> getPositions(int n) {
    vector<int> positions;

    int idx = 0;
    while(n > 0) {

        if(n % 2 == 1) positions.push_back(idx);

        n /= 2;
        idx++;
    }
    return positions;
}


int solution(int N) {
    vector<int> positions = getPositions(N);

    // for(int i = 0 ; i < positions.size(); i++) {
    //     cout<<positions[i]<<' ';
    // }
    // cout<<endl;

    int ans = 0;

    for(int i = 1 ;  i < positions.size() ; i++ ){
        ans = max(ans, positions[i] - positions[i - 1] - 1);
    }

    return ans;
}