#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 40001;

int n;
int dp[100001];

void solve() {
    fill(dp + 1, dp + 100001, INF);

    for(int i = 1; i < 350; i++) {
        int val = i * i;
        for(int j = 1; j <= 1e5; j++) {
            if(j >= val) {
                dp[j] = min(dp[j], dp[j - val] + 1);
            }
        }
    }
}

int main(void) {
    FASTIO;
    cin >> n;
    solve();
    cout << dp[n] << '\n';

    return 0;
}