#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m, src, dst;
int indgree[10001], cost[10001];
bool visited[10001];
vector<pair<int, int>> adj[10001], radj[10001];

void topologySort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int c = adj[cur][i].second;

            cost[next] = max(cost[next], cost[cur] + c);
            if(--indgree[next] == 0)
                q.push(next);
        }
    }
}

int dfs(int cur) {
    if(cur == src) return 1;

    int ret = 0;
    for(int i = 0; i < radj[cur].size(); i++) {
        int next = radj[cur][i].first;
        int c = radj[cur][i].second;
        if(cost[cur] - c == cost[next]) {
            if(visited[next]) ret++;
            else {
                visited[next] = true;
                ret += dfs(next);
            }
        }
    }
    if(cur == dst) return ret;
    return ret + 1;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    int s, e, t;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        adj[s].push_back({e, t});
        radj[e].push_back({s, t});
        indgree[e]++;
    }
    cin >> src >> dst;

    topologySort();
    cout << cost[dst] << '\n';
    visited[dst] = true;
    cout << dfs(dst) << '\n';


    return 0;
}