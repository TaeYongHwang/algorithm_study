#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode;
typedef struct TreeNode TreeNode;


struct TreeNode {
	int numbering; //0 : �ܺ�, 1���� ��������
	int level; //-1�� �ϴ� �ʱ�ȭ���ѳ���.
	TreeNode * parent;
	vector<TreeNode*> children;

};





//big �ȿ� small�� ���ԵǾ��ִ� ��쿡. true
bool is_include(TreeNode* big, TreeNode* small, vector<pair<int, pair<int, int>>>& v)
{
	int big_r = v[big->numbering].first;
	int big_x = v[big->numbering].second.first;
	int big_y = v[big->numbering].second.second;

	int sm_r = v[small->numbering].first;
	int sm_x = v[small->numbering].second.first;
	int sm_y = v[small->numbering].second.second;


	return big_r > sm_r &&
		(pow(big_y - sm_y, 2) + pow(big_x - sm_x, 2)) < pow(big_r - sm_r, 2);

	
}

int dfs(TreeNode* tree, TreeNode* wall, vector<pair<int, pair<int, int>>>& v)
{
	
	for (int i = 0; i < tree->children.size(); i++) {
		if(dfs(tree->children[i], wall,v) ==1)
			return 1;
	}

	if (is_include(tree, wall,v)){
		wall->parent = tree;
		tree->children.push_back(wall);
		return 1;
	}


	return 0;

}



TreeNode* make_tree(vector<pair<int, pair<int, int>>>& v)
{
	//��ó�� ��Ʈ����.
	TreeNode* tree = new TreeNode;
	int number = 0;
	tree->numbering = number++;
	tree->level = -1;
	tree->parent = NULL;
	
	//�� �������� ��� Ʈ��ȭ��Ű������ ���� ����(N-1)��ŭ �ݺ������ش�.
	for (int i = 0; i < v.size()-1; i++) {
		TreeNode* wall = new TreeNode;
		wall->numbering = number++;
		wall->level = -1;
		wall->parent = NULL;

		//�ش� ������ ��� ���� �ȿ� �ִ����� �Ǻ��ؾ� �Ѵ�.(DFS�̿�)
		dfs(tree, wall, v);
	}
	return tree;
}


vector<int> ans;
int longest;
//���� ū ���� ã�Ƽ� ��ȯ��Ų��.
int find_max(TreeNode* tree, vector<pair<int, pair<int, int>>>& v)
{
	/*
	vector<int> heights;
	for (int i = 0; i < tree->children.size(); i++)
		heights.push_back(find_max(tree->children[i],v));

	if (heights.empty())
		return 0;
	sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	return heights.back() + 1;

	*/



	
	int max_value = -1;
	//basecase : leaf node�� ���
	if (tree->children.size() == 0) {
		ans.push_back(0);
		return tree->level = 0;
	}
	
	//����->������ dfs
	for (int i = 0; i < tree->children.size(); i++) {
	    find_max(tree->children[i], v);
	}
	
	//�ڽĵ� ������ ������������ ����
	vector<int> level;
	for (int i = 0; i < tree->children.size(); i++) {
		level.push_back(tree->children[i]->level);
	}
	sort(level.begin(), level.end(), greater< int>());
	
	if (level.size() == 1) {
		ans.push_back(level[0]+1);
		return tree->level = level[0] + 1;
	}
	else {
		ans.push_back(level[0] + 1);
		ans.push_back(level[0] + level[1]+2);
		tree->level = level[0] + 1;
		return level[0] + level[1]+2;
	}

	
}

int solve(TreeNode* tree, vector<pair<int, pair<int, int>>>& v) {
	longest = 0;
	int h = find_max(tree,v);
	return max(longest, h);
}


int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int N; //������ ��
		cin >> N;
		
		vector< pair<int, pair<int, int> > > v;

		while (N--) {
			//������, x,y ��
			pair<int, pair<int, int>> temp;
			//x,y,r ������ ����
			cin >> temp.second.first >> temp.second.second >> temp.first;
			v.push_back(temp);
		}

		//������ ������ �������� ���Ľ�Ű��
		sort(v.begin(), v.end(), greater< pair<int, pair<int, int> >>());
		TreeNode* tree =make_tree(v);
		find_max(tree, v);

		sort(ans.begin(), ans.end(), greater<int>());
	
		/*
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << endl;
		*/
		cout << ans[0] << endl;
		//cout << solve(tree, v) << endl;

		ans.clear();
	}
	return 0;
}