#include <vector>
#include <algorithm>
#include <cmath>

int solution(vector<int> &A) {
    vector<int> accumulated;
    accumulated.push_back(A[0]);
    for(int i = 1 ; i < A.size() ; i ++) {
        accumulated.push_back(accumulated[i-1] + A[i]);
    }


    int ans = 2000000000;
    for(int i = 0 ; i < accumulated.size() - 1 ; i++) {
        int left = accumulated[i];
        int right = accumulated[accumulated.size() -1] - accumulated[i];

        ans = min(ans , abs(left - right));
    }


    return ans;
}