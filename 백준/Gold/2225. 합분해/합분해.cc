#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, k;
int dp[40001];

void solve() {
    for(int i = 0; i <= n; i++)
        dp[i] = 1;

    for(int i = 2; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    } 
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    solve();
    cout << dp[n] << '\n';

    return 0;
}