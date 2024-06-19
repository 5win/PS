#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, k;
string arr[15];
int nums[15];
int decimalMod[52];
LL dp[100][1 << 15];

LL dfs(int visited, int num) {
    if(visited == (1 << n) - 1) {
        if(num % k == 0) return 1;
        return 0;
    }

    LL &ret = dp[num][visited];
    if(ret != -1) return ret;

    LL cnt = 0;
    for(int next = 0; next < n; next++) {
        if(visited & (1 << next)) continue;
        cnt += dfs(visited | (1 << next), (num * decimalMod[arr[next].size()] + nums[next]) % k);
    }
    return ret = cnt;
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    decimalMod[0] = 1;
    for(int i = 1; i <= 51; i++) {
        decimalMod[i] = (decimalMod[i - 1] * 10) % k;
    }

    for(int i = 0; i < n; i++) {
        int len = arr[i].size();
        for(int j = 0; j < len; j++) {
            nums[i] = (nums[i] + (arr[i][len - j - 1] - '0') * decimalMod[j]) % k;
        }
    }

    memset(dp, -1, sizeof(dp));
    LL up = dfs(0, 0);
    LL down = 1;
    for(int i = 1; i <= n; i++)
        down *= i;
    LL g = gcd(down, up); 
    cout << up / g << "/" << down / g << '\n';

    return 0;
}