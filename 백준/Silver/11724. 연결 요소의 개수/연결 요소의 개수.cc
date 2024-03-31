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
vector<int> adj[1001];

int bfs() {
    queue<int> q;
    int visited[1001] = {0, };
    int ret = 0;

    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        ret++;        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int i = 0; i < adj[cur].size(); i++) {
                if(visited[adj[cur][i]]) continue;
                visited[adj[cur][i]] = true;
                q.push(adj[cur][i]);
            }
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