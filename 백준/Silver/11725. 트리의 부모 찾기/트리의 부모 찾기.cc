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
vector<int> adj[100001];
bool visited[100001];
int parent[100001];

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            if(visited[adj[cur][i]]) continue;
            visited[adj[cur][i]] = true;
            parent[adj[cur][i]] = cur;
            q.push(adj[cur][i]);
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    for(int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
    
    return 0;
}