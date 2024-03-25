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
long long dp[100];

int main(void) {

    cin >> n;
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    cout << dp[n] << endl;
    
    return 0;
}