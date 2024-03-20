#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
long long dp[100][2];

int main(void) {

    cin >> n;

    dp[1][1] = 1;   // 1
    dp[2][0] = 1;   // 10
    dp[3][0] = 1;   // 100
    dp[3][1] = 1;   // 101 
    // 1 10 100 101
    // 1000 1001 1010
    // 10000 10001 10010 10100 10101

    for(int i = 4; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n][0] + dp[n][1] << endl;

    return 0;
}