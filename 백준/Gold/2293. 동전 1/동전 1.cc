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
int cost[101];
int dp[10001];

void solve() {
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        int v = cost[i];
        for(int j = 1; j <= k; j++) {
            if(j >= v)
                dp[j] += dp[j - v];
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    solve();
    cout << dp[k] << '\n';

    return 0;
}