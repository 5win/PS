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
const int MAX_V = 401;

int n, m;
int adj[MAX_V][MAX_V];

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        fill(adj[i], adj[i] + n + 1, INF);
        adj[i][i] = 0;
    }
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    floyd();

    int res = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            res = min(res, adj[i][j] + adj[j][i]);
        }
    }
    if(res >= INF)
        cout << "-1\n";
    else
        cout << res << '\n';

    return 0;
}