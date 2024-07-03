#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, m;
int arr[2001];
bool dp[2001][2001];

void solve() {
    for(int i = 1; i <= n; i++) 
        dp[i][i] = true;

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            int j = i + k;
            if(j > n) continue;
            if(arr[i] == arr[j] && (dp[i + 1][j - 1] || k == 1)) {
                dp[i][j] = true;
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    solve();

    cin >> m;
    while(m--) {
        int s, e;
        cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }


    return 0;
}