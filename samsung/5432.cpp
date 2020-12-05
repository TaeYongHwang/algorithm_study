#include <iostream>
#include <string>

using namespace std;

const int LEFT_END = 1 , RIGHT_END = 2, LASER = 3;


int kindOf(string& prob, int idx) {
    if(idx == prob.length()) {
        return RIGHT_END;
    }  

    if(prob[idx] == '(' && prob[idx+1] == ')')    return LASER;
    if(prob[idx] == '(')    return LEFT_END;
    return RIGHT_END;
}


int findAns(string& prob) {
    int count = 0;
    int partition_number = 0;

    for(int i = 0 ; i < prob.length() ; i++) {
        int kind = kindOf(prob, i);

        switch (kind) {
            case LEFT_END:
                count ++;
                partition_number ++;
                break;
        
            case RIGHT_END:
                count --;
                break;
            
            case LASER:
                partition_number += count;
                i++;
                break;
        }
    }

    return partition_number;
}


int main() {

    int T;
    cin >> T;

    for(int tc = 1 ; tc <=T ; tc++) {
        string problem;
        cin >> problem;

        cout<<'#'<<tc<<' '<<findAns(problem)<<endl;


    }





}