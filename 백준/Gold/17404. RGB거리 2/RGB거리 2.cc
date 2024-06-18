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
int dp[1001][3];

int solve() {
	int ret = INF;

	for(int start = 0; start < 3; start++) {
		memset(dp, 0, sizeof(dp));
		for(int color = 0; color < 3; color++) {
			if(start == color)
				dp[1][color] = cost[1][color];
			else
				dp[1][color] = INF;
		}

		for(int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}	

		for(int color = 0; color < 3; color++) {
			if(start == color) continue;
			ret = min(ret, dp[n][color]);
		}
	}
	return ret;
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	cout << solve() << '\n';

    return 0;
}