#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

const int MOD = 1000000000;

int n;
int dp[101][10];

int main(void) {

    cin >> n;

    for(int i = 1; i < 10; i++)
        dp[1][i] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for(int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    int res = 0;
    for(int i = 0; i < 10; i++)
        res = (res + dp[n][i]) % MOD;
    cout << res << endl;
    
    return 0;
}