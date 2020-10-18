#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> ans;
unordered_map<string, bool> findStr;
unordered_map<string, vector<string>> m;

void dfs(vector<string>& strs) {
	for (int i = 0; i < strs.size(); i++) {
		if (findStr[strs[i]] == false) {
			findStr[strs[i]] = true;
			ans.push_back(strs[i]);
			dfs(m[strs[i]]);

		}
	}

}



int main() {
	int n; cin >> n;
	 {
		string a, b, c; cin >> a >> c >> b;
		m[a].push_back(b);
		findStr[a] = 0;
	}

	dfs(m["Baba"]);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}