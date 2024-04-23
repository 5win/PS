#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m;
int dp[31][31];

int main(void) {
    FASTIO;

    int w = 30, e = 30;
    for(int i = 1; i <= e; i++) {
        dp[1][i] = i;
        dp[i][i] = 1;
    }
    for(int i = 2; i <= w; i++) {
        for(int j = 2; j <= e; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
    }

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
    
    return 0;
}