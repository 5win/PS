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
const int MOD = 1e9 + 7;
const int MAX_X = 400004;

struct SEGTREE {
    vector<int> rangeRet;
    int len;

    SEGTREE(int n) {
        len = n;
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        rangeRet.resize(powered * 2);
    }

    int insert(int idx, int node, int left, int right) {
        if(idx < left || right < idx) return rangeRet[node];
        if(left == right) return rangeRet[node] = (rangeRet[node] + 1) % MOD;
        int mid = (left + right) / 2;
        return rangeRet[node] = (insert(idx, node * 2, left, mid) + insert(idx, node * 2 + 1, mid + 1, right)) % MOD; 
    }
    int insert(int idx) {
        return insert(idx, 1, 0, len - 1);
    }

    int query(int l, int r, int node, int nLeft, int nRight) {
        if(r < nLeft || nRight < l) return 0;
        if(l <= nLeft && nRight <= r) return rangeRet[node];
        int mid = (nLeft + nRight) / 2;
        return (query(l, r, node * 2, nLeft, mid) + query(l, r, node * 2 + 1, mid + 1, nRight)) % MOD;
    }
    int query(int l, int r) {
        return query(l, r, 1, 0, len - 1);
    }
};

int n;
vector<pair<int, int>> p;

bool compX(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

void compress() {
    int rank = -1, prev = INF;
    for(auto& i : p) {
        if(prev != i.second) {
            rank++;
            prev = i.second;
        }
        i.second = rank;
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        p.push_back({-y, x});
    }
    sort(p.begin(), p.end(), compX);
    compress();
    sort(p.begin(), p.end());

    SEGTREE tree(MAX_X);

    int answer = 0;
    int prevY = p[0].first;
    queue<int> q;
    for(auto i : p) {
        if(prevY != i.first) {
            while(!q.empty()) {
                tree.insert(q.front());
                q.pop();
            }
            prevY = i.first;
        }
        q.push(i.second);
        int leftSum = tree.query(0, i.second - 1);
        int rightSum = tree.query(i.second + 1, MAX_X - 1);
        answer = (answer + ((long long)leftSum * rightSum) % MOD) % MOD;
    }
    cout << answer << '\n';

    return 0;
}   