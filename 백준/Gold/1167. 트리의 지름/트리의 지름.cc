#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n;
vector<pair<int, int>> adj[100001];
bool visited[100001];
int res;

int dfs(int cur, int cost) {
    int mx = 0;
    int ret = 0;

    for(int i = 0; i < adj[cur].size(); i++) {
        if(visited[adj[cur][i].first]) continue;
        visited[adj[cur][i].first] = true;
        ret = dfs(adj[cur][i].first, adj[cur][i].second);
        res = max(res, ret + mx);
        mx = max(mx, ret);
    }
    return mx + cost;
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u;
        while(true) {
            cin >> v;   if(v == -1) break;
            cin >> w;   adj[u].push_back({v, w});
        }
    }
    visited[1] = true;
    dfs(1, 0);
    cout << res << '\n';
    
    return 0;
}   