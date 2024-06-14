#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n;
int dp[32];

int dfs(int here) {
    if(here == n + 1) return 1;
    if(here > n + 1) return 0;

    int sum = 0;
    sum += dfs(here + 2) * 3;
    for(int i = 4; here + i <= n + 1; i += 2) {
        sum += dfs(here + i) * 2;
    }
    return sum;
}

int main(void) {
    FASTIO;

    cin >> n;
    cout << dfs(1) << '\n';

    return 0;
}