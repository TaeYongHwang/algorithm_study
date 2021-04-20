
#include <unordered_map>


int solution(vector<int> &A) {
    unordered_map<int, int> m;

    for(int i = 0 ; i < A.size() ; i ++) {
        m[A[i]]++;
    }

    for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        if(it->second % 2 == 1) return it->first;
    }

}