#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int k;
int dp[501][501];
int psum[501];
vector<int> arr(501);

void solve() {

    for(int l = 0; l < k; l++) {
        for(int i = 1; i <= k - l; i++) {
            int j = i + l;
            int tmp = INF;
            for(int m = i; m < j; m++) {
                tmp = min(tmp, dp[i][m] + dp[m + 1][j] + (psum[j] - psum[i - 1]));
            }
            if(tmp == INF)
                dp[i][j] = 0;
            else
                dp[i][j] = tmp;
        }
    }
}

void prefixSum() {
    for(int i = 1; i <= k; i++) {
        psum[i] = psum[i - 1] + arr[i];
    }
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        arr.clear();
        memset(dp, 0, sizeof(dp));
        memset(psum, 0, sizeof(psum));
        cin >> k;
        for(int i = 1; i <= k; i++) 
            cin >> arr[i];
        prefixSum();
        solve();
        
        cout << dp[1][k] << '\n';
    }

    
    return 0;
}