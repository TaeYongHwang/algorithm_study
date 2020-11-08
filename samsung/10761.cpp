#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> orangeButton, blueButton;
vector<pair<char, int>> allButton; 
int orangeCount = 0, blueCount = 0;

/** 행동 **/
void action(int& src, int& desc, char who ,char curTurn) {

    if(desc == -1) return;
    if(who == 'O' && orangeCount == orangeButton.size()) return;
    if(who == 'B' && blueCount == blueButton.size()) return;

    if(src < desc ) {
        src ++;
    } else if ( src > desc ) {
        src --;
    } else {
        if(who == curTurn) {
            if(who == 'O') {
                orangeCount ++;
            } else {
                blueCount ++;
            }
        }
    }
}


/** 최소 시간 반환 - 함수 1회는 1초를 의미 **/
int find(int orangeIdx = 1, int blueIdx = 1) {
    // 마지막 처리
    if(orangeCount + blueCount == allButton.size()) return 0;


    char curTurn = allButton[orangeCount + blueCount].first;
    int orangeButtonIdx, blueButtonIdx;


    // cout << orangeIdx <<' '<< blueIdx<< ' '<< curTurn << endl;



    if(orangeButton.size() != 0){
        orangeButtonIdx = orangeButton[orangeCount];
    } else {
        orangeButtonIdx = -1;
    }

    if(blueButton.size() != 0) {
        blueButtonIdx = blueButton[blueCount];
    } else {
        blueButtonIdx = -1;
    }

    
    //오렌지 움직임 
    action(orangeIdx, orangeButtonIdx, 'O', curTurn);
    //블루 움직임
    action(blueIdx, blueButtonIdx, 'B', curTurn);

    return 1 + find(orangeIdx, blueIdx);

}





int main() {
    int tc;

    cin >> tc;
    
    int curTestNum = 1;

    while(tc--) {
        int buttonNum;
        cin >> buttonNum;

        for(int i = 0 ; i < buttonNum ; i ++) {
            char who;
            int press;
            cin >> who >> press;

            allButton.push_back({ who, press });

            if(who == 'O') {
                orangeButton.push_back(press);
            } else {
                blueButton.push_back(press);
            }
        }
        /*
        for(int i = 0 ; i <allButton.size() ; i++) {
            cout<< allButton[i].first << allButton[i].second << endl;
        }
        */

        int result = find();

        //cout <<"result :" << result<<endl;
        cout<<'#'<< curTestNum++ << ' ' << result<<endl;

        orangeButton.clear();
        blueButton.clear();
        allButton.clear();
        orangeCount = 0;
        blueCount = 0;



    }




}