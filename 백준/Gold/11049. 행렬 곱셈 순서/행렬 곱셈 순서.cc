#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n;
int dp[501][501];
vector<pair<int, int>> mtrx;

void solve() {

    for(int gap = 1; gap < n; gap++) {
        for(int i = 0; i < n - gap; i++) {
            int j = i + gap;
            int tmp = INT_MAX;
            for(int k = i; k < j; k++) {
                tmp = min(tmp, dp[i][k] + dp[k + 1][j] + (mtrx[i].first * mtrx[k].second * mtrx[j].second));
            }
            dp[i][j] = tmp;
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        mtrx.push_back({r, c});
    }
    solve();
    cout << dp[0][n - 1] << '\n';
    
    return 0;
}