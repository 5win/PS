#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, m;
int coin[21];
int dp[100001];

void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        int cost = coin[i];
        for(int j = 1; j <= m; j++) {
            if(j >= cost)
                dp[j] = dp[j - cost] + dp[j];
        }
    }
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> coin[i];
        }
        cin >> m;
        solve();
        cout << dp[m] << '\n';
    }

    return 0;
}