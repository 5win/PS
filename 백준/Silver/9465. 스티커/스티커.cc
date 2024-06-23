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
int sticker[3][int(1e6 + 1)];
int dp[3][int(1e6 + 1)];

bool inRange(int y, int x) {
    return 0 < y && y < 3 && 0 < x && x <= n;
}

void solve() {

    dp[1][1] = sticker[1][1];
    dp[2][1] = sticker[2][1];
    dp[1][2] = sticker[2][1] + sticker[1][2];
    dp[2][2] = sticker[1][1] + sticker[2][2];
    for(int c = 3; c <= n; c++) {
        dp[1][c] = max(dp[2][c - 1], dp[2][c - 2]) + sticker[1][c];
        dp[2][c] = max(dp[1][c - 1], dp[1][c - 2]) + sticker[2][c];
    }
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= n; j++)
                cin >> sticker[i][j];
        solve();
        cout << max(dp[1][n], dp[2][n]) << '\n'; 
    }

    return 0;
}