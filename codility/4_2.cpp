#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <iostream>

vector<int> solution(int N, vector<int> &A) {

    int maxV = 0;
    int tempMax = 0;

    unordered_map<int, int> m;
    for(int i = 0 ; i < A.size() ; i++) {
        int value = A[i];

        if(value != N + 1) {
            tempMax = max(tempMax, ++m[value-1]);
        } else {
            maxV += tempMax;
            tempMax = 0;
            m.clear();
        }
    }

    vector<int> answers = vector<int>(N, maxV);

    for(unordered_map<int,int>::iterator it = m.begin() ; it != m.end() ; it++) {
        answers[it->first] += it->second;
    }

    return answers;
}