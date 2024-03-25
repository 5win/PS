#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int n;
int T[20], P[20];
int dp[20];

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = n - 1; i >= 0; i--) {
        if(i + T[i] <= n) {
            dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
        }
        else
            dp[i] = dp[i + 1];
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, dp[i]);
    cout << res << endl;
    
    return 0;
}