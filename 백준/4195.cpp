//disjoint set È°¿ë

#include<cstdio>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

unordered_map <string, pair<string, int>> map;

pair<string,int> findParent(string man) {
	if (map[man].first == man)
		return map[man];

	return map[man] = findParent(map[man].first);
	

}

int merge(string man1, string man2) {
	if (map.find(man1) == map.end()) {
		map[man1] = { man1, 1 };
	}
	if (map.find(man2) == map.end()) {
		map[man2] = { man2, 1 };
	}

	pair<string, int> p1 = findParent(man1);
	pair<string, int> p2 = findParent(man2);


	if (p1.first == p2.first) {
		return p1.second;
	}
	else {
		map[p2.first].first = p1.first;
		map[p1.first].second += p2.second;
		
		
		return map[p1.first].second;
	}

}


int main() {

	cin.tie(0);
	int T, F;
	cin >> T;

	while (T--) {
		map.clear();
		cin >> F;
		while (F--) {
			string man1, man2;
			cin >> man1 >> man2;

			cout << merge(man1, man2) << '\n';
			/*
			unordered_map<string, pair<string, int>>::iterator it;
			for (it = map.begin(); it != map.end(); it++) {
				cout << "name : " << it->first << " parent: " << it->second.first << " num : " << it->second.second << endl;
			}
			*/

		}
	}





	return 0;
}