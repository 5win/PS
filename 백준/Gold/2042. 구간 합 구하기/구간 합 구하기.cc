#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

struct SEGTREE {
    int len;
    vector<long long> rangeSum;
    SEGTREE(const vector<long long>& array) {
        len = array.size();
        rangeSum.resize(len * 4);
        init(array, 0, len - 1, 1);
    }

    long long init(const vector<long long>& array, int left, int right, int node) {
        if(left == right)
            return rangeSum[node] = array[left];
        int mid = (left + right) / 2;
        long long leftSum = init(array, left, mid, node * 2);
        long long rightSum = init(array, mid + 1, right, node * 2 + 1);
        return rangeSum[node] = leftSum + rightSum;
    }

    long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return 0;
        if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
        int mid = (nodeLeft  + nodeRight) / 2;
        return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
    }
    long long query(int left, int right) {
        return query(left, right, 1, 0, len - 1);
    }
    
    long long update(int index, long long newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return rangeSum[node];
        if(nodeLeft == nodeRight) return rangeSum[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeSum[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
    }

    long long update(int index, long long newValue) {
        return update(index, newValue, 1, 0, len - 1);
    }
};

int n, m, k;
vector<long long> arr;
SEGTREE *tree;

int main(void) {
    FASTIO;

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        long long tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    tree = new SEGTREE(arr);

    for(int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1) {
            tree->update(b - 1, c);
        } else {
            cout << tree->query(b - 1, c - 1) << '\n';
        }
        
    }


    return 0;
}