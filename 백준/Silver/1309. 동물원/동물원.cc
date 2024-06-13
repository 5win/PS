#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 9901;
const int MAX = 40001;

int n;
int dp[100001];

void solve() {
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
}

int main(void) {
    FASTIO;

    cin >> n;
    solve();
    cout << dp[n] << '\n';

    return 0;
}