#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;


struct SEGTREE {
    int len;
    vector<LL> rangeRet;
    SEGTREE(const vector<pair<int, int>>& arr) {
        len = arr.size();
        int powered = 1;
        while(powered < len) {
            powered <<= 1;
        }
        rangeRet.resize(powered * 2, 0);
    }    

    LL query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return 0;
        if(left <= nodeLeft && nodeRight <= right) return rangeRet[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
    }
    LL query(int left, int right) {
        return query(left, right, 1, 0, len - 1);
    }

    LL update(int index, int newValue, int node, int nLeft, int nRight) {
        if(index < nLeft || nRight < index) return rangeRet[node];
        if(nLeft == nRight) return rangeRet[node] = newValue;
        int mid = (nLeft + nRight) / 2;
        return rangeRet[node] = update(index, newValue, node * 2, nLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nRight);
    }
    LL update(int index, int newValue) {
        return update(index, newValue, 1, 0, len - 1);
    }
};

int n;
vector<pair<int, int>> arr;
SEGTREE *tree;

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int  tmp; cin >> tmp;
        arr.push_back({tmp, i});
    }

    tree = new SEGTREE(arr);

    sort(arr.begin(), arr.end());

    long long sum = 0;
    int prev = -1;
    vector<int> idxs;
    for(int i = 0; i < arr.size(); i++) {
        int val = arr[i].first, idx = arr[i].second;
        if(prev != val) {
            for(auto i : idxs) 
                tree->update(i, 1);
            idxs.clear();
            prev = val;
        }
        sum += tree->query(idx + 1, n - 1);
        idxs.push_back(idx);
    }
    cout << sum << '\n';

    return 0;
}