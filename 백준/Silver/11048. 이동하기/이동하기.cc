#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 40001;

int n, m;
int dp[1001][1001];

void solve() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] += max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> dp[i][j];
    solve();
    cout << dp[n][m] << '\n'; 

    return 0;
}