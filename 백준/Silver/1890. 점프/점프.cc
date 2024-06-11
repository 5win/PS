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
int board[101][101];
LL dp[101][101];

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

void solve() {
    dp[0][0] = 1;

    int ny, nx;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == 0) continue;
            if(board[i][j] == 0) continue;
            ny = i;
            nx = j + board[i][j];
            if(inRange(ny, nx))
                dp[ny][nx] += dp[i][j];
            ny = i + board[i][j];
            nx = j;
            if(inRange(ny, nx))
                dp[ny][nx] += dp[i][j]; 
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    solve();

    cout << dp[n - 1][n - 1] << '\n';

    return 0;
}