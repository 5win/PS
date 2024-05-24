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

void setLevel(int node) {
    int cnt = 0;
    int cur = node;
    while(parent[cur]) {
        cur = parent[cur];
        cnt++;
    }
    level[node] = cnt;
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i <= n; i++) adj[i].clear();
        memset(parent, 0, sizeof(parent));
        memset(level, 0, sizeof(level));

        int u, v;
        for(int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            parent[v] = u;
        }
        for(int i = 1; i <= n; i++) {
            setLevel(i);
        }
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}