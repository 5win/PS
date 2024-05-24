#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n;
vector<int> adj[10001];
int parent[10001], level[10001];

int lca(int u, int v) {
    if(level[u] < level[v]) swap(u, v);

    while(level[u] != level[v]) {
        u = parent[u];
    }

    while(u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

void setTree(int node, int pnode) {
    parent[node] = pnode;
    level[node] = level[pnode] + 1;

    for(auto& next : adj[node]) {
        if(pnode == next) continue;
        setTree(next, node);
    }
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i <= n; i++) {
            adj[i].clear();
            parent[i] = i;
        }
        memset(level, 0, sizeof(level));

        int u, v;
        for(int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            parent[v] = u;        // parent
            adj[u].push_back(v);  // dfs를 위한 간선
        }
        for(int i = 1; i <= n; i++) {
            if(parent[i] == i) {
                setTree(i, i);
            }
        }
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }


    return 0;
}