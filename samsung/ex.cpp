#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
    map<string, int> m;

    //m.insert({"idx", 0});
    m["idx"] = 0;
    m["idx"] = 0;



    cout<< (*m.find("idx")).first <<endl;
    cout<< m["idx"]<<endl;
    cout<<m.count("idx")<<endl;










}