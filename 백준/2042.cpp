#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

class SegTree {
    public:
        vector<long long> tree;
        int height;
        int leafStart;

    //SegTree tree(a.size());
    SegTree(int n) {
        height = ceil(log2(n));
        tree = vector<long long>(1 << (height + 1));
    }

    //Ex) init(a, 1, 0, a.size() -1);
    long long init(vector<long long> &a, int node, int start, int end) {
        long long& ret = tree[node];

        if(start == end) return ret = a[start];

        int mid = (start + end) / 2;

        return ret = init(a, node * 2, start, mid) + init(a, node * 2 + 1, mid+1, end);
    }

    long long sum(int node, int start, int end, int left, int right) {
        if(right < start || left  > end) {
            return 0;
        }

        if(left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) /2;

        return  sum(node*2, start, mid, left, right) + sum(node*2 +1, mid + 1, end, left, right);
    }

    void update(int node,  int start, int end, int idx, long long diff) {
        if(idx < start || idx > end) return;

        tree[node] = tree[node] + diff;
        if (start != end) {
            int mid = (start + end) / 2;
            update(node*2, start, mid, idx, diff);
            update(node*2 +1, mid+1, end, idx, diff);
        }
    }
};

int main() {
    int N, M, K;

    cin >> N >> M >> K;

    vector<long long> nums;

    for(int i = 0 ; i < N ; i++) {
        long long tmp;
        scanf("%lld", &tmp);
        nums.push_back(tmp);
    }
    
    SegTree segTree(nums.size());
    segTree.init(nums, 1, 0, nums.size() -1);


    for(int i = 0 ; i < M + K ; i++) {
        int a;
        scanf("%d", &a);

        if(a == 1) {
            int b;
            long long c;
            scanf("%d %lld", &b, &c);
            b--;

            long long diff = c - nums[b];
            nums[b] = c;
            segTree.update(1, 0, nums.size() -1, b, diff);
        } else {
            int b, c;
            scanf("%d %d", &b, &c);
            b--;
            c--;

            printf("%lld\n", segTree.sum(1, 0, nums.size() -1, b, c));
        }

    }










}