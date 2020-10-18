#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair<string, pair < char, int>>> candidate;
vector <string> ans;

int main()
{
	string myName, myPreference;
	int dist, N;

	cin >> myName >> myPreference >> dist >> N;

	for (int i = 0; i < N; i++) {
		string name;
		char gender;
		int temp;
		cin >> name >> gender >> temp;
		//candidate.push_back({ name, {gender,temp} });

		if (myPreference.size() != 1) {
			if (temp <= dist)
				ans.push_back(name);
		}
		else
		{
			if (gender == myPreference[0])
				if (temp <= dist)
					ans.push_back(name);
		}

	}


	if (ans.size() == 0)
		cout << "No one yet" << endl;
	else
	{
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}

	return 0;
}