#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int dp[1000001];
int trace[1000001];

int main(void) {

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    trace[2] = 1;
    trace[3] = 1;

    for(int i = 4; i <= n; i++) {
        int mn = INT_MAX;
        if(i % 3 == 0 && mn > dp[i / 3]) {
            trace[i] = i / 3;
            mn = dp[i / 3];
        }
        if(i % 2 == 0 && mn > dp[i / 2]) {
            trace[i] = i / 2;
            mn = dp[i / 2];
        }
        if(mn > dp[i - 1]) {
            trace[i] = i - 1;
            mn = dp[i - 1];
        }
        dp[i] = mn + 1;
    }

    cout << dp[n] << endl;
    cout << n << ' ';
    while(n > 1) {
        n = trace[n];
        cout << n << ' ';
    }
    cout << '\n';

    return 0;
}