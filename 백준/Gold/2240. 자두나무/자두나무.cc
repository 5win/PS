#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int t, w;
int jadu[1001];
int dp[1001][3][31];

int dfs(int time, int loc, int shift) {
    if(time == t) return 0;

    int &ret = dp[time][loc][shift];
    if(ret != -1) return ret;

    int mx = 0;
    if(loc == jadu[time]) {
        mx = max(mx, dfs(time + 1, loc, shift) + 1);
    } else {
        mx = dfs(time + 1, loc, shift);
        if(shift > 0)
            mx = max(mx, dfs(time + 1, jadu[time], shift - 1) + 1);
    }
    return ret = mx;
}

int main(void) {
    FASTIO;

    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> jadu[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1, w) << '\n';

    return 0;
}