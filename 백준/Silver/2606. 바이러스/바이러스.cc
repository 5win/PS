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

int n, m;
vector<int> adj[101];

int bfs() {
    int ret = 0;
    bool visited[101] = {0, };

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            if(visited[adj[cur][i]]) continue;
            visited[adj[cur][i]] = true;
            q.push(adj[cur][i]);
            ret++;
        }
    }
    return ret;
}

int main(void) {
    FASTIO;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << bfs() << '\n';

    return 0;
}