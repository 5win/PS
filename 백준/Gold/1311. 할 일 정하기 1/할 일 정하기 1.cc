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
int D[21][21];
int dp[1 << 20];

int dfs(int cur, int done) {
    if(cur == n) {
        return 0;
    }

    int &ret = dp[done];
    if(ret != -1) return ret;

    int mn = INF;
    for(int i = 0; i < n; i++) {
        if(done & (1 << i)) continue;
        mn = min(mn, dfs(cur + 1, done | (1 << i)) + D[cur][i]);
    }
    return ret = mn;
}

int main(void) {
    FASTIO;

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> D[i][j];
        }
    }
    cout << dfs(0, 0) << '\n';

    return 0;
}