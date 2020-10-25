#include <iostream>
#include <vector>
#include <utility>

using namespace std;


int find(vector<pair<int,int>>& line) {
    int count = 0;

    for(int i = 0 ; i < line.size() ; i++) {
        for(int j = i+1; j < line.size() ; j++) {
            pair<int, int> cur = line[i];
            pair<int, int> next = line[j];

            if(cur.first > next.first && cur.second < next.second) {
                count ++;
            } else if(cur.first < next.first && cur.second > next.second) {
                count ++; 
            }
        }
    }

    return count;

}




int main() {
    int tc;
    int count = 0;

    cin >> tc;

    while(count ++ < tc) {
        vector<pair<int,int>> line;
        int lineNum;
        
        cin>> lineNum;

        while(lineNum --) {
            int a,b;
            cin >> a >> b;
            line.push_back({a, b});
        }

        cout<<'#'<<count<<' '<<find(line)<<endl;
    }
}