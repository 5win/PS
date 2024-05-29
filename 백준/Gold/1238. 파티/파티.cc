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

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;

int n, m, x;
int adj[1001][1001];

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(adj[i][k] >= INF) continue;
            for(int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = INF;
            if(i == j) adj[i][j] = 0;
        }
    }
        
    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        adj[s][e] = t;
    }

    floyd();

    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(res, adj[i][x] + adj[x][i]);
    }
    cout << res << '\n';

    return 0;
}