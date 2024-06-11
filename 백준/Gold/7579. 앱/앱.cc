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
int sum = 0;
int A[101];
int cost[101];
int dp[101][10001];

void solve() {
    for(int i = 1; i <= n; i++)
        sum += cost[i];

    for(int i = 1; i <= n; i++) {
        int c = cost[i];
        for(int j = 0; j <= sum; j++) {
            if(j >= c) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c] + A[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    for(int i = 1; i <= n; i++)
        cin >> cost[i];

    solve();

    int res = INF;
    for(int i = 0; i <= sum; i++) {
        if(dp[n][i] >= m) {
            res = min(res, i);
        }
    }
    cout << res << '\n';

    return 0;
}