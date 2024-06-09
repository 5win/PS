#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n, m;
int adj[101][101];
int route[101][101];

void floyd() {

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(adj[i][j] > adj[i][k] + adj[k][j])  {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
}

void printRoute(int u, int v, vector<int>& path) {
    if(route[u][v] == -1) {
        path.push_back(u);
        path.push_back(v);
        return;
    }
    int k = route[u][v];
    printRoute(u, k, path);
    path.pop_back();
    printRoute(k, v, path);
}

void printResult() {
    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] == INF)
                cout << "0 ";
            else 
                cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    vector<int> path;
    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            path.clear();
            printRoute(i, j, path);
            cout << path.size() << ' ';
            for(int i : path)
                cout << i << ' ';
            cout << '\n';
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;

    memset(route, -1, sizeof(route));
    for(int i = 1; i <= n; i++) {
        fill(adj[i], adj[i] + n + 1, INF);
    }

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
    }

    floyd();
    printResult();

    return 0;
}