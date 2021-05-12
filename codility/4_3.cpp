#include <vector>

int solution(vector<int> &A) {
    vector<bool> finded = vector<bool>(1000001, false);

    for(int i = 0 ; i < A.size() ; i++) {
        if(A[i] > 0 ) finded[A[i]] = true;
    }

    for(int i = 1 ; i < finded.size() ; i++) {
        if(!finded[i]) return i;
    }

}