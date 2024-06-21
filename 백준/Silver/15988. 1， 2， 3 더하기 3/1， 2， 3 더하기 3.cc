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
int dp[1000001];

void solve() {
    fill(dp, dp + 1000001, 1);

    for(int i = 1; i <= 3; i++) {
        for(int j = 2; j <= 1e6; j++) {
            int tmp = 0;
            for(int k = 1; k <= i; k++) {
                if(j >= k)
                    tmp = (tmp + dp[j - k]) % MOD;
            }
            dp[j] = tmp;
        }
    }
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