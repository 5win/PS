#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 40001;

int n, k;
int coin[101];
int dp[101][10001];

void solve() {
    fill(dp[0], dp[0] + k + 1, INF);

    for(int i = 1; i <= n; i++) {
        int cost = coin[i];
        for(int j = 1; j <= k; j++) {
            if(j >= cost) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - cost] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    solve();
    if(dp[n][k] == INF)
        cout << "-1\n";
    else
        cout << dp[n][k] << '\n';

    return 0;
}