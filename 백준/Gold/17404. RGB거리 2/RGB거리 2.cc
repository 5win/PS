#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 10007;
const int MAX = 40001;

int n;
int cost[1001][3];
int dp[1001][3][3];

int dfs(int start, int prev, int here) {
	if(here == n) {
		return 0;
	}

	int &ret = dp[here][prev][start];
	if(ret != -1) return ret;

	int mn = INF;
	for(int i = 0; i < 3; i++) {
		if(prev == i) continue;
		if(here == n - 1 && start == i) continue;
		mn = min(mn, dfs(start, i, here + 1) + cost[here][i]);
	}
	return ret = mn;
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	int res = INF;
	for(int i = 0; i < 3; i++) {
		res = min(res, dfs(i, i, 1) + cost[0][i]);
	}
	cout << res << '\n';

    return 0;
}