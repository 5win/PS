#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9 + 3;
const int MAX = 40001;

int n, k;
int dp[1001][1001];

void solve() {
	for(int i = 1; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}

	for(int i = 2; i < n; i++) {
		for(int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}
	for(int j = 1; j <= k; j++) {
		dp[n][j] = (dp[n - 3][j - 1] + dp[n - 1][j]) % MOD;
	}
}

int main(void) {
    FASTIO;

	cin >> n >> k;
	solve();
	cout << dp[n][k] << '\n';

    return 0;
}