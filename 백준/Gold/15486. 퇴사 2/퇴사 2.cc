#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

const int MAX = 1500002;
int n;
int T[MAX], P[MAX];
int dp[MAX];

int main(void) {

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        if(i + T[i] - 1 <= n) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }

    cout << max(dp[n], dp[n + 1]) << endl;
    
    return 0;
}