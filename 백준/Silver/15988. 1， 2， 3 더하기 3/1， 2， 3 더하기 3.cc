#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9 + 9;
const int MAX = 40001;

int n;
int dp[int(1e6 + 1)];

void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 1e6; i++)
        dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    solve();
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}