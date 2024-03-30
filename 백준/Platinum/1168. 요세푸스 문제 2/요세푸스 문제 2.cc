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
    int size;
    vector<int> rangeRet;
    SEGTREE() {
        len = 100001;
        size = 0;
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        rangeRet.resize(powered * 2, 0);
    }

    int update(int idx, int node, int nLeft, int nRight, int val) {
        if(idx < nLeft || nRight < idx) return rangeRet[node];
        if(nLeft == nRight) {
            rangeRet[node] += val;
            size += val;
            return rangeRet[node];
        }
        int mid = (nLeft + nRight) / 2;
        return rangeRet[node] = update(idx, node * 2, nLeft, mid, val) + update(idx, node * 2 + 1, mid + 1, nRight, val);
    }

    int update(int idx, int val) {
        return update(idx, 1, 0, len - 1, val);
    }

    int query(int target, int node, int nLeft, int nRight) {
        if(nLeft == nRight) return nLeft;
        int mid = (nLeft + nRight) / 2;
        if(target <= rangeRet[node * 2])
            return query(target, node * 2, nLeft, mid);
        else
            return query(target - rangeRet[node * 2], node * 2 + 1, mid + 1, nRight);
    }

    int query(int target) {
        return query(target, 1, 0, len - 1);
    }
};

int n, k;

int main(void) {
    FASTIO;

    cin >> n >> k;
    SEGTREE tree;
    for(int i = 1; i <= n; i++)
        tree.update(i, 1);

    vector<int> res;
    int step = 1;
    for(int i = 0; i < n; i++) {
        int size = tree.size;
        step = (step - 1 + k) % size;
        step = (step == 0) ? size : step;
        int nextNum = tree.query(step);
        tree.update(nextNum, -1);
        res.push_back(nextNum);
    }

    cout << "<";
    for(int i = 0; i < n - 1; i++)
        cout << res[i] << ", ";
    cout << res[n - 1] <<">\n";
        
    return 0;
}