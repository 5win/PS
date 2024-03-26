#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
vector<int> adj[1001];
vector<bool> visited(1001, false);

int bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int v = 0; v < adj[cur].size(); v++) {
            int nextV = adj[cur][v];
            if(visited[nextV]) continue;
            visited[nextV] = true;
            cnt++;
            q.push(nextV);
        }
    }
    return cnt;
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        // visited.resize(1001, false);
        visited.assign(1001, false);
        // visited = vector<bool>(1001, false);

        int a, b;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << bfs() << '\n';
    }

    return 0;
}