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

struct MinMax {
    int mn, mx;
};

struct SEGTREE {
    int len;
    vector<MinMax> rangeRet;
    SEGTREE(int n) {
        len = n;
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        rangeRet.resize(powered * 2);
        init(0, len - 1, 1);
    }

    MinMax merge(const MinMax& a, const MinMax& b) {
        int mn = min(a.mn, b.mn);
        int mx = max(a.mx, b.mx);
        return  {mn, mx};
    }

    MinMax init(int left, int right, int node) {
        if(left == right) return rangeRet[node] = {left, left};
        int mid = (left + right) / 2;
        MinMax leftRet = init(left, mid, node * 2);
        MinMax rightRet = init(mid + 1, right, node * 2 + 1);
        return rangeRet[node] = merge(leftRet, rightRet);
    }

    MinMax query(int l, int r, int node, int nLeft, int nRight) {
        if(r < nLeft || nRight < l) return {INT_MAX, INT_MIN};
        if(l <= nLeft && nRight <= r) return rangeRet[node];
        int mid = (nLeft + nRight) / 2;
        return merge(query(l, r, node * 2, nLeft, mid), query(l, r, node * 2 + 1,  mid + 1, nRight));
    }
    MinMax query(int l, int r) {
        return query(l, r, 1, 0, len - 1);
    }

    MinMax update(int idx, int newVal, int node, int nLeft, int nRight) {
        if(idx < nLeft || nRight < idx) return rangeRet[node];
        if(nLeft == nRight) return rangeRet[node] = {newVal, newVal};
        int mid = (nLeft + nRight) / 2;
        return rangeRet[node] = merge(update(idx, newVal, node * 2, nLeft, mid), update(idx, newVal, node * 2 + 1, mid + 1, nRight));
    }
    MinMax update(int idx, int newVal) {
        return update(idx, newVal, 1, 0, len -1);
    }
};

int n, k;
vector<int> arr;

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        arr.clear();
        cin >> n >> k;
        SEGTREE tree(n);
        for(int i = 0; i < n; i++)
            arr.push_back(i);

        int q, a, b;
        for(int i = 0; i < k; i++) {
            cin >> q >> a >> b;
            if(q) {
                MinMax res = tree.query(a, b);
                if(res.mn == a && res.mx == b)
                    cout << "YES\n";
                else
                    cout << "NO\n";    
            } else {
                swap(arr[a], arr[b]);                
                tree.update(a, arr[a]);
                tree.update(b, arr[b]);
            }
        }
    }

    return 0;
}