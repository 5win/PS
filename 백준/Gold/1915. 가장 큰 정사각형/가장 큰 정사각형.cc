#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, m;
string arr[1001];
int dp[1001][1001];

void solve() {

    for(int i = 0; i < n; i++) 
        dp[i][0] = arr[i][0] == '0' ? 0 : 1;
    for(int j = 0; j < m; j++)
        dp[0][j] = arr[0][j] == '0' ? 0 : 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == '0') continue;
            int mn = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            dp[i][j] = mn + 1;
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve();
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res = max(res, dp[i][j] * dp[i][j]);

    cout << res << '\n';

    return 0;
}