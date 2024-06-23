#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9 + 9;
const int MAX = 40001;

int n, m;
int dp[41][41];
bool vip[41];

int dfs(int prev, int here) {
    if(here == n + 1) {
        return 1;
    }

    int &ret = dp[prev][here];
    if(~ret) return ret;

    if(vip[here]) {
        if(prev == here) return 0;
        return ret = dfs(here, here + 1);
    }

    int sum = 0;
    if(prev == here - 1) {
        sum += dfs(here, here + 1);
        if(here + 1 <= n)
            sum += dfs(here + 1, here + 1);
    } else if(prev == here - 2) {
        sum += dfs(here, here + 1);
        if(here + 1 <= n)
            sum += dfs(here + 1, here + 1);
    } else if(prev == here) {
        sum += dfs(here - 1, here + 1);
    }
    return ret = sum;
}

int main(void) {
    FASTIO;

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int idx; cin >> idx;
        vip[idx] = true;
    }
    if(vip[1] || n == 1)
        cout << dfs(1, 2) << '\n';
    else 
        cout << dfs(1, 2) + dfs(2, 2) << '\n';

    return 0;
}