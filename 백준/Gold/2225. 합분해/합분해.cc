#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, k;
int dp[201][40001];

int dfs(int cnt, int curSum) {
    if(cnt == k) {
        if(curSum == n) return 1;
        else return 0;
    }
    if(curSum > n) return 0;

    int &ret = dp[cnt][curSum];
    if(ret != -1) return ret;
    
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum = (sum + dfs(cnt + 1, curSum + i)) % MOD;
    }
    return ret = sum;
}

int main(void) {
    FASTIO;

    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << dfs(0, 0) << '\n';

    return 0;
}