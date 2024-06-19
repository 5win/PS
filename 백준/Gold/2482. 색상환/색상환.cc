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

int dfs(int here, int len, bool chkStart) {
	if(len == k) {
		return 1;
	}

	int &ret = dp[here][len];
	if(ret != -1) return ret;

	int cnt = 0;
	for(int next = here + 2; next <= n; next++) {
		if(chkStart && next == n) continue;
		cnt = (cnt + dfs(next, len + 1, chkStart)) % MOD;
	}
	return ret = cnt;
}

int main(void) {
    FASTIO;

	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	int res = dfs(0, 0, false);
	memset(dp, -1, sizeof(dp));
	res = (res + dfs(1, 1, true)) % MOD;
	cout << res << '\n';

    return 0;
}