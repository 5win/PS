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

int dfs(int sum) {
    if(sum == 0) return 1;
    else if(sum < 0) return 0;

    int &ret = dp[sum];
    if(ret != -1) return ret;

    int cnt = 0;
    for(int i = 1; i <= 3; i++) {
        cnt = (cnt + dfs(sum - i)) % MOD;
    }
    return ret = cnt;
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--) {
        cin >> n;
        cout << dfs(n) << '\n';
    }

    return 0;
}