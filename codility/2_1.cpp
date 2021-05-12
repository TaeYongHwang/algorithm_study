#include <vector>

vector<int> solution(vector<int> &A, int K) {

    if(A.size() == 0) return A;

    for(int i = 0 ; i < K ; i++) {
        int back = A.back();
        A.pop_back();

        A.insert(A.begin(), back);
    }

    return A;
}