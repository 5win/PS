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

struct SEGTREE {
    int len;
    vector<long long> rangeMul;

    SEGTREE(const vector<long long>& arr) {
        len = arr.size();
        
        int powered = 1;
        while(powered < len) {
            powered = powered << 1;
        }

        rangeMul.resize(powered * 2);
        init(arr, 0, len - 1, 1);
    }

    long long init(const vector<long long>& arr, int left, int right, int node) {
        if(left == right) return rangeMul[node] = arr[left];
        int mid = (left + right) / 2;
        long long leftMul = init(arr, left, mid, node * 2);
        long long rightMul = init(arr, mid + 1, right, node * 2 + 1);
        return rangeMul[node] = (leftMul * rightMul) % MOD;
    }

    long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return 1;          // 부분 곱이므로 1을 반환
        if(left <= nodeLeft && nodeRight <= right) return rangeMul[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return (query(left, right, node * 2, nodeLeft, mid) * query(left, right, node * 2 + 1, mid + 1, nodeRight)) % MOD;
    }

    long long query(int left, int right) {
        return query(left, right, 1, 0, len - 1);
    }

    long long update(int index, long long newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return rangeMul[node];
        if(nodeLeft == nodeRight) return rangeMul[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMul[node] = (update(index, newValue, node * 2, nodeLeft, mid) * update(index, newValue, node * 2 + 1, mid + 1, nodeRight)) % MOD;
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