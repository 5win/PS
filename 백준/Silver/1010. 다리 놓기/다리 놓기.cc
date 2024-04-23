#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m, ans;
int cache[31][31];

int dfs(int cur, int cnt) {

    int& ret = cache[cur][cnt];
    if(ret != -1)
        return ret;

    if(cnt == n) {
        return 1;
    }

    int sum = 0;
    for(int i = cur + 1; i < m; i++) {
        sum += dfs(i, cnt + 1);
    }
    return ret = sum;
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        ans = 0;
        cin >> n >> m;
        int ans = 0;
        for(int i = 0; i < m; i++)
            ans += dfs(i, 1);
        cout << ans << '\n';
    }
    
    return 0;
}