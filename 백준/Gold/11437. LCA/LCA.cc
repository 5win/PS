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

int n, m;
vector<int> adj[50001];
int parent[50001], level[50001];

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
    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(next == pnode) continue;
        setTree(next, node);
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    setTree(1, 1);
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }


    return 0;
}