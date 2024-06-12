#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 40001;

int n;
int dp[100001];

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> dp[i];
    
    int res = -INF;
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + dp[i], dp[i]);
        res = max(res, dp[i]);
    }
    cout << res << '\n';

    return 0;
}