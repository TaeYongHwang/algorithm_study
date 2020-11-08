#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> mix;
vector<int> ans;

int LEFT = -1;
int RIGHT = 1;

void swap(vector<int>& v, int src, int desc) {
    int temp = src;
    v[src] = desc;
    v[desc] = temp;
}

int getBallLocation(vector<int>& v) {
    for(int i = 0 ; i< v.size() ; i++) {
        if(v[i] == 1) return i;
    }
}

int trick(vector<int>& v, int idx, int dir) {
    if(dir > 0) {
        v[idx] = 0;
        v[idx+1] = 1;
        return idx +1;
    } else {
        v[idx] = 0;
        v[idx-1] = 1;
        return idx - 1;
    }
 }

bool isTrick(vector<int>&v, int ballLocation, int dir) {
    if(dir > 0 && v.size() == ballLocation + 1) return false;
    if(dir < 0 && ballLocation - 1 == 0) return false;

    return true; 
}

void find(vector<int>& v, int count = 0, bool useTrick = false) {

    /** 종료 **/ 
    if(count == mix.size()) {    
        int ballLocation = getBallLocation(v);

        if(find(ans.begin(), ans.end(), ballLocation) == ans.end()) {
            ans.push_back(ballLocation);
        }
        return;
    } 

    // 트릭 안쓴 경우 트릭 사용
    if(!useTrick) {
        // 오른쪽 트릭 후 위치 변경
        int ballLocation = getBallLocation(v);
        if(isTrick(v, ballLocation, RIGHT)) {
            ballLocation = trick(v, ballLocation, RIGHT);
            swap(v, mix[count].first, mix[count].second);
            find(v, count + 1, true);
            swap(v, mix[count].second, mix[count].first);
            ballLocation = trick(v, ballLocation, LEFT);
        }

        if(isTrick(v, ballLocation, LEFT)) {    
            // 왼쪽 트릭 후 위치변경
            ballLocation = trick(v, ballLocation, LEFT);
            swap(v, mix[count].first, mix[count].second);
            find(v, count + 1, false);
            swap(v, mix[count].second, mix[count].first);
            ballLocation = trick(v, ballLocation, RIGHT);

        }

    }
    
    // 트릭 안쓰고 변경
    swap(v, mix[count].first, mix[count].second);
    find(v, count + 1, useTrick);
    swap(v, mix[count].first, mix[count].second);


}





int main() {
    int tc, count = 0;
    cin >> tc;

    while(count++ < tc) {
        int N,Q, src, desc;
        cin >> N >> Q;

        while(Q--) {
            cin >> src >> desc;
            mix.push_back({src, desc});
        }

        vector<int> v;
        v.assign(N + 1,0);
        v[1] = 1;

        find(v);

        cout<<'#'<<count<<' '<<ans.size()<<endl;
    

        mix.clear();
        ans.clear();
    }
}