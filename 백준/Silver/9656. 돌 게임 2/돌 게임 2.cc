#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n;
bool dp[1001];

int main(void) {
    FASTIO;
    
    cin >> n;
    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    for(int i = 4; i <= n; i++) {
        dp[i] = !(dp[i - 1] && dp[i - 3]);
    }
    if(dp[n])
        cout << "SK";
    else
        cout << "CY";


    return 0;
}