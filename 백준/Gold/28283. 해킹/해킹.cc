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

int n, m, x, y;
vector<int> adj[500001];
queue<int> q;
int A[500001];
long long visited[500001];

void bfs() {
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto i : adj[cur]) {
            if(visited[i]) continue;
            visited[i] = visited[cur] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m >> x >> y;
    int input;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < m; i++) {
        int s, e;   cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    for(int i = 0; i < y; i++) {
        cin >> input;
        visited[input] = 1;
        q.push(input);
    }
    bfs();

    for(int i = 1; i <= n; i++) {
        if(!visited[i] && A[i] != 0) {
            cout << "-1\n"; return 0;
        }
        visited[i] = (visited[i] - 1) * A[i];
    }

    sort(visited + 1, visited + n + 1);

    long long sum = 0;
    for(int i = n; i > n - x; i--)
        sum += visited[i];
    cout << sum << '\n';

    return 0;
}   