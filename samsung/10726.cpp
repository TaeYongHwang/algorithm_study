#include <iostream>
#include <vector>

using namespace std;


bool find(int num, int count) {
    
    if(count == 0 ) {
        return true;
    }

    if(num % 2 == 1) {
        return find(num / 2, count -1);
    }

    return false;
}


int main() {
    int tc;

    cin >> tc;
    int count = 0 ;

    while(count++ < tc) {
        int n, m;
        cin >> n >> m;

        
        if(find(m,n)) {
            cout<<'#'<<count<<' '<<"ON"<<endl;
        } else {
            cout<<'#'<<count<<' '<<"OFF"<<endl;
        }








    } 








}