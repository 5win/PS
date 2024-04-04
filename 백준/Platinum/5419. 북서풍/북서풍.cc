#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

struct SEGTREE {
    int len;
    vector<int> rangeRet;

    SEGTREE(vector<pair<int, int>>& arr) {
        len = arr.size();
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        rangeRet.resize(powered * 2);
    }

    int update(int val, int idx, int node, int left, int right) {
        if(idx < left || right < idx) return rangeRet[node];
        if(left == right) return rangeRet[node] += val;
        int mid = (left + right) / 2;
        return rangeRet[node] = update(val, idx, node * 2, left, mid) + update(val, idx, node * 2 + 1, mid + 1, right);
    }

    int query(int l, int r, int node, int nLeft, int nRight) {
        if(nRight < l || r < nLeft) return 0;
        if(l <= nLeft && nRight <= r) return rangeRet[node];
        int mid = (nLeft + nRight) / 2;
        return query(l, r, node * 2, nLeft, mid) + query(l, r, node * 2 + 1, mid + 1, nRight);
    }

};

int n;
vector<pair<int, int>> p;

bool compareY(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

void compress() {
    sort(p.begin(), p.end(), compareY);
    int rank = -1;
    int prev = INF;
    for(int i = 0; i < n; i++) {
        if(prev != p[i].second) {
            rank++;
            prev = p[i].second;
        }
        p[i].second = rank;
    }
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        cin >> n;
        p.clear();
        int x, y;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            p.push_back({x, -y});
        }
        compress();
        sort(p.begin(), p.end());   // x로 먼저 정렬해야함

        SEGTREE tree(p);
        long long sum = 0;
        for(int i = 0; i < p.size(); i++) {
            sum += tree.query(0, p[i].second, 1, 0, n - 1);
            tree.update(1, p[i].second, 1, 0, n - 1);
        }
        cout << sum << '\n';
    }

    return 0;
}   