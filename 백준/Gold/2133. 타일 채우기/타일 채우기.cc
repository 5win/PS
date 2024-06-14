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
int dp[32];

void solve() {
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = dp[2] * 3 + 2;

    for(int i = 6; i <= n; i++) {
        if(i % 2 == 1) continue;
        dp[i] += dp[i - 2] * 3;
        for(int j = 4; i - j >= 0; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    solve();
    cout << dp[n] << '\n';

    return 0;
}