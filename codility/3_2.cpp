#include <vector>


int solution(vector<int> &A) {

    if(A.size() == 0) return 1;

    vector<bool> existed = vector<bool>(A.size() + 1, false);

    for(int i = 0 ; i < A.size() ; i++) {
        existed[A[i]] = true;
    }


    for(int i = 1 ; i < existed.size() ; i++) {
        if(!existed[i]) return i;
    }

}
