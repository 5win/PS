#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

struct SEGTREE {
    int len;
    vector<LL> rangeRet;

    SEGTREE(const vector<int>& arr) {
        len = arr.size();
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        rangeRet.resize(powered * 2);
        init(arr, 1, 0, len - 1);
    }

    void init(const vector<int>& arr, int node, int l, int r) {
        if(l == r) {
            rangeRet[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        init(arr, node * 2, l, mid);
        init(arr, node * 2 + 1, mid + 1, r);
    }

    LL query(int idx, int node, int nLeft, int nRight) {
        if(idx < nLeft || nRight < idx) return 0;
        // if(l <= nLeft && nRight <= r) return rangeRet[node];
        if(nLeft == nRight) return rangeRet[node];
        int mid = (nLeft + nRight) / 2;
        return rangeRet[node] + query(idx, node * 2, nLeft, mid) + query(idx, node * 2 + 1, mid + 1, nRight);
    }

    LL query(int idx) {
        return query(idx, 1, 0, len - 1);
    }

    void update(int l, int r, int node, int val, int nLeft, int nRight) {
        if(r < nLeft || nRight < l) return;
        if(l <= nLeft && nRight <= r) {
            rangeRet[node] += val;
            return;
        }
        int mid = (nLeft + nRight) / 2;
        update(l, r, node * 2, val, nLeft, mid);
        update(l, r, node * 2 + 1, val, mid + 1, nRight);
    }

    void update(int l, int r, int val) {
        return update(l ,r, 1, val, 0, len - 1);
    }
};

int n, m;
vector<int> arr;

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    SEGTREE tree(arr);

    cin >> m;
    int a, b, c, k;
    for(int i = 0; i < m; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> k;
            tree.update(b - 1, c - 1, k);
        } else {
            cin >> b;
            cout << tree.query(b - 1) << '\n';
        }
    }

    return 0;
}