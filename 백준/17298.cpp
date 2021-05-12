#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
#include <utility>

int N;

using namespace std;

int main() {
    cin >> N;
    vector<pair<int,int>> numbers;
    for(int i = 0 ; i < N ; i++) {
        int tmp;
        scanf("%d", &tmp);
        numbers.push_back({tmp, i});
    }

    stack<pair<int, int>> S;
    vector<int> answers = vector<int>(N, -1);

    for(int i = 0 ; i < N ; i++) {
        pair<int,int> target = numbers[i];

        while(!S.empty() && S.top().first < target.first) {
            pair<int,int> top = S.top();
            S.pop();
            answers[top.second] = target.first;

        }

        S.push(target);
    }

    for(int i = 0 ; i < answers.size() ; i++) {
        printf("%d ",answers[i]);

    }

   return 0;
}