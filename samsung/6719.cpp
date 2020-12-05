#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> courses;



double findAns(int N, int K) {
    sort(courses.begin(), courses.end());

    double ans = 0;

    for(int i = N - K ; i < N ; i++) {
        ans = (ans + courses[i]) / 2;
    }
    return ans;    

}



int main() {
    int T;
    cin >> T;

    for(int tc = 1 ; tc <= T ; tc++) {
        int N, K;
        cin >> N >> K;
        courses = vector<int>(N, 0);
        

        for(int i = 0 ; i < N ; i ++) {
            cin >> courses[i];
        }

        cout<<'#'<<tc<<' '<<findAns(N,K)<<endl;
    }



}