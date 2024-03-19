#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;

int main(void) {

    cin >> n;
    int dp[1000001] = {0, };
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        int mn = 1987654321;
        if(i % 3 == 0) 
            mn = dp[i / 3] + 1;
        if(i % 2 == 0)
            mn = min(mn, dp[i / 2] + 1);
        mn = min(mn, dp[i - 1] + 1);
        dp[i] = mn;
    }
    cout << dp[n] << endl;

    return 0;
}