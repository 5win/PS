#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n, m;
int board[501][501];
int dp[501][501];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(int y, int x) {
    int &ret = dp[y][x];
    if(ret != -1)
        return ret;
    
    if(y == n - 1 && x == m - 1) 
        return ret = 1;

    int cur = board[y][x];
    int sum = 0;
    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if(!inRange(ny, nx) || board[ny][nx] >= cur) continue;
        sum += dfs(ny, nx);
    }
    return ret = sum;
}

int main(void) {
    FASTIO;

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0) << '\n';
    
    return 0;
}