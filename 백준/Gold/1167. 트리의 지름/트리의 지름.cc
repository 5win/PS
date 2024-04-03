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
int visited[100001];

int bfs(int start) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    int ret = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < adj[cur].size(); i++) {
            int nNode = adj[cur][i].first;
            int nWeight = adj[cur][i].second;
            if(visited[nNode]) continue;
            visited[nNode] = visited[cur] + nWeight;
            q.push(nNode);

            ret = (visited[ret] > visited[nNode]) ? ret : nNode;
        }
    }
    return ret;
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u;
        while(true) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back({v, w});
        }
    }
    // cout << visited[bfs(bfs(1))] - 1 << '\n';
    int maxDistV = bfs(1);
    maxDistV = bfs(maxDistV);
    cout << visited[maxDistV] - 1 << '\n';
    
    return 0;
}   