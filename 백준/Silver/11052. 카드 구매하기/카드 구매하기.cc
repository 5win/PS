#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 40001;

int n;
int p[1001];
int dp[1001];

void solve() {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - i] + p[i]);
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    solve();
    cout << dp[n] << '\n';

    return 0;
}