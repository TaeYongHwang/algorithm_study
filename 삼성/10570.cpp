#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector <int> v; 


bool isPalindrome(int num) {
    string numberStr = to_string(num);

    int start = 0;
    int end = numberStr.length() -1;
    
    while(start < end) {
        if(numberStr[start] != numberStr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}


void find(int idx = 1) {
    if(idx == 32) {
        return;
    }

    if(isPalindrome(idx) && isPalindrome(idx * idx)) {
        v[idx] = v[idx-1] +1;
    } else {
        v[idx] = v [idx - 1];
    }
    find(idx+1); 
}





int main() {
    v.assign(32,0);
    find();

    int ts;
    int count = 0;

    cin >> ts;

    while(count ++ < ts) {
        int start, end;
        cin >> start >> end;

        start = ceil(sqrt(start));
        end = floor(sqrt(end));

        // cout<<start<<' '<<end<<endl;

        cout<<'#'<<count<<' '<<v[end] - v[start - 1]<<endl;

    } 



}