#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int n, m;
vector<int> parent(1000002), setRank(1000002, 1);

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(setRank[u] > setRank[v]) swap(u, v);
    parent[u] = v;          // u가 포함된 트리의 루트가 v가 포함된 루트로
    if(setRank[u] == setRank[v]) setRank[v]++;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op) {
            if(find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            merge(a, b);
        }
    } 

    return 0;
}