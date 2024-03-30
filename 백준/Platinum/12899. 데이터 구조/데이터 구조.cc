#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

struct SEGTREE {
    int len;
    vector<int> rangeRet;
    SEGTREE() {
        len = 2000001;
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        rangeRet.resize(powered * 2, 0);
    }

    int update(int idx, int node, int nLeft, int nRight) {
        if(idx < nLeft || nRight < idx) return rangeRet[node];
        if(nLeft == nRight) {
            rangeRet[node]++;
            return rangeRet[node];
        }
        int mid = (nLeft + nRight) / 2;
        int ret = update(idx, node * 2, nLeft, mid) + update(idx, node * 2 + 1, mid + 1, nRight);
        return rangeRet[node] = ret;
    }

    int update(int idx) {
        return update(idx, 1, 0, len - 1);
    }

    int query(int target, int node, int nLeft, int nRight) {
        if(nLeft == nRight) {
            rangeRet[node]--;
            // cout << nLeft << ", " << rangeRet[node] << endl;
            return nLeft;
        }
        int mid = (nLeft + nRight) / 2;
        int ret;
        // cout  << target << ", " << rangeRet[node * 2] << ", " << rangeRet[node * 2 + 1] << '\n';
        if(target <= rangeRet[node * 2]) {
            ret = query(target, node * 2, nLeft, mid);
        }
        else {
            ret = query(target - rangeRet[node * 2], node * 2 + 1, mid + 1, nRight);
        }
        rangeRet[node] = rangeRet[node * 2] + rangeRet[node * 2 + 1];
        return ret;
    }

    int query(int target) {
        return query(target, 1, 0, len - 1);
    }
};

int n;

int main(void) {
    FASTIO;

    cin >> n;
    int a, b;
    SEGTREE tree;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a == 1) {
            tree.update(b);
        } else {
            cout << tree.query(b) << '\n';
        }
    }

    return 0;
}