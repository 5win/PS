#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;
const int MOD = 1000000007;

struct MinMax {
    int minVal, maxVal;
};

struct SEGTREE {

    int len;
    vector<MinMax> rangeRet;

    SEGTREE(const vector<int>& arr) {
        len = arr.size();
        
        int powered = 1;
        while(powered < len) {
            powered <<= 1;
        }

        rangeRet.resize(powered * 2);
        init(arr, 0, len - 1, 1);
    }

    MinMax merge(const MinMax& a, const MinMax& b) {
        int mn = min(a.minVal, b.minVal);
        int mx = max(a.maxVal, b.maxVal);
        return {mn, mx};
    }

    MinMax init(const vector<int>& arr, int left, int right, int node) {
        if(left == right) return rangeRet[node] = {arr[left], arr[left]};
        int mid = (left + right) / 2;
        MinMax leftRet = init(arr, left, mid, node * 2);
        MinMax rightRet = init(arr, mid + 1, right, node * 2 + 1);
        return rangeRet[node] = merge(leftRet, rightRet);
    }

    MinMax query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return {INT_MAX, INT_MIN};          // 부분 곱이므로 1을 반환
        if(left <= nodeLeft && nodeRight <= right) return rangeRet[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return merge(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    MinMax query(int left, int right) {
        return query(left, right, 1, 0, len - 1);
    }

    MinMax update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return rangeRet[node];
        if(nodeLeft == nodeRight) return rangeRet[node] = {newValue, newValue};
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeRet[node] = merge(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }

    MinMax update(int index, int newValue) {
        return update(index, newValue, 1, 0, len - 1);
    }
};


int n, m;
vector<int> arr;
SEGTREE *tree;

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    tree = new SEGTREE(arr);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        MinMax res = tree->query(a - 1, b - 1);
        cout << res.minVal << ' ' << res.maxVal << '\n';
    }

    return 0;
}