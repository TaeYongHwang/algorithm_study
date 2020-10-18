#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;

int v[1000001];

int find(int idx) {

	if (v[idx] == idx)
		return idx;

	else
		return v[idx] = find(v[idx]); // path compression (�̰� �����ָ� �ع� ������ �н��� �˻��ؾ� �ϱ� ������ �ð��ʰ���. -> ����� DP�ε�?)
}


void merge(int set1, int set2) {
	v[find(set2)] = find(set1);

}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i <= n; i++)
		v[i] = i;

	while (m--) {
		int op, set1, set2;
		scanf("%d %d %d", &op, &set1, &set2);

		if (op== 0) {
			merge(set1, set2);

		}
		else {
			if (find(set1) == find(set2))
				printf("YES\n");
			else
				printf("NO\n");
		}

	}
	return 0;
}