#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>
#include <math.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 1987654321;
const int MAX = 40000;

struct POINT {
    int x, y1, y2, val;

    POINT(int x, int y1, int y2, int val) {
        this->x = x;
        this->y1 = y1;
        this->y2 = y2;
        this->val = val;
    }
};

struct SEGTREE {
    vector<int> cnt, rangeRet;
    int len;

    SEGTREE(int n) {
        len = n;
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        cnt.resize(powered * 2);
        rangeRet.resize(powered * 2);
    }

    int update(int val, int l, int r, int node, int nLeft, int nRight) {
        if(r < nLeft || nRight < l) return 0;
        else if(l <= nLeft && nRight <= r) {
            cnt[node] += val;
        }
        else {
            int mid = (nLeft + nRight) / 2;
            int leftRet = update(val, l, r, node * 2, nLeft, mid);
            int rightRet = update(val, l, r, node * 2 + 1, mid + 1, nRight);
        }
        if(cnt[node]) {
            return rangeRet[node] = nRight - nLeft + 1;
        } else {
            if(nLeft == nRight) return rangeRet[node] = 0;
            else return rangeRet[node] = rangeRet[node * 2] + rangeRet[node * 2 + 1];
        }
    }

    int update(int val, int l, int r) {
        return update(val, l, r, 1, 0, len - 1);
    }
};

int n;
vector<POINT> p;

bool compX(POINT& a, POINT& b) {
    return a.x < b.x;
}

int main(void) {
    FASTIO;

    cin >> n;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        p.push_back(POINT(x1, y1, y2, 1));
        p.push_back(POINT(x2, y1, y2, -1));
    }
    sort(p.begin(), p.end(), compX);
    SEGTREE tree(MAX);

    int ans = 0;
    int prevX = p[0].x;
    for(int i = 0; i < p.size(); i++) {
        ans += (p[i].x - prevX) * tree.rangeRet[1];
        tree.update(p[i].val, p[i].y1, p[i].y2 - 1);
        prevX = p[i].x;
    }
    cout << ans << '\n';

    return 0;
}