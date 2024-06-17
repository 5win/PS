#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n;
int W[16][16];
int dp[16][1 << 16];

int dfs(int here, int visited) {
    if(visited == (1 << n) - 1) {
        if(W[here][0] == 0) return INF;
        return W[here][0];
    }

    int &ret = dp[here][visited];
    if(ret != -1) return ret;

    int mn = INF;
    for(int next = 0; next < n; next++) {
        if(visited & (1 << next) || W[here][next] == 0) continue;
        mn = min(mn, dfs(next, visited | (1 << next)) + W[here][next]); 
    }
    return ret = mn;
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1) << '\n';

    return 0;
}