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
int dp[1001][1001][2];

int dfs(int here, int len, int chkStart) {
	if(len == k) {
		if(here == n + 2 && chkStart)
			return 0;
		return 1;
	}

	if(here > n) return 0;

	int &ret = dp[here][len][chkStart];
	if(ret != -1) return ret;

	return ret = (dfs(here + 1, len, chkStart) + dfs(here + 2, len + 1, chkStart)) % MOD;
}

int main(void) {
    FASTIO;

	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << (dfs(2, 0, 0) + dfs(3, 1, 1)) % MOD << '\n';

    return 0;
}