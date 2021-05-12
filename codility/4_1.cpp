#include <unordered_map>

int solution(int X, vector<int> &A) {

    unordered_map<int,int> m;

    for(int i =0 ; i < A.size(); i++) {
        m[A[i]]++;

        if(m.size() == X) return i;
    }



    return -1;
}