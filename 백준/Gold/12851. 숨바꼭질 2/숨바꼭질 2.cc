#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n, k;
int dp[100001];
vector<int> visited(100001, -1);

bool inRange(int x) {
    return 0 <= x && x <= 100000;
}

void bfs() {
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    dp[n] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop(); 
        if(inRange(cur - 1)) {
            if(visited[cur - 1] == -1) {
                visited[cur - 1] = visited[cur] + 1;
                q.push(cur - 1);
                dp[cur - 1] = dp[cur];
            } else if(visited[cur - 1] == visited[cur] + 1) {
                dp[cur - 1] += dp[cur];
            }
        }
        if(inRange(cur + 1)) {
            if(visited[cur + 1] == -1) {
                visited[cur + 1] = visited[cur] + 1;
                q.push(cur + 1);
                dp[cur + 1] = dp[cur];
            } else if(visited[cur + 1] == visited[cur] + 1) {
                dp[cur + 1] += dp[cur];
            }
        }
        if(inRange(cur * 2)) {
            if(visited[cur * 2] == -1) {
                visited[cur * 2] = visited[cur] + 1;
                q.push(cur * 2);
                dp[cur * 2] = dp[cur];
            } else if(visited[cur * 2] == visited[cur] + 1) {
                dp[cur * 2] += dp[cur];
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    bfs();
    cout << visited[k] << '\n';
    cout << dp[k] << '\n';

    return 0;
}