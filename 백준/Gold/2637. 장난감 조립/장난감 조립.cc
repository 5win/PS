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

int n, m;
int indgree[101], outdgree[101], ans[101];
vector<pair<int, int>> adj[101];

void topologySort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
            ans[i] = 1;
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int cost = adj[cur][i].second;

            ans[next] += ans[cur] * cost;
            if(--indgree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    int x, y, k;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> k;
        adj[x].push_back({y, k});
        indgree[y]++;
        outdgree[x]++;
    }
    topologySort();
    for(int i = 1; i <= n; i++) {
        if(outdgree[i] == 0)
            cout << i << ' ' << ans[i] << '\n';
    }

    return 0;
}