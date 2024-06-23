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
int dp[41];
bool vip[41];

int solve() {
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int sum = 1;
    int s = 1;
    for(int i = 1; i <= n; i++) {
        if(vip[i]) {
            sum *= dp[i - s];
            s = i + 1;
        }
    }
    if(s != n + 1) {
        sum *= dp[n + 1 - s];
    }
    return sum;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int idx; cin >> idx;
        vip[idx] = true;
    }
    cout << solve() << '\n';

    return 0;
}