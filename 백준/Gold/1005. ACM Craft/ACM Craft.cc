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

int n, k, w;
int D[1001], ans[1001], indgree[1001];
vector<int> adj[1001];

void topologySort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
            ans[i] = D[i];
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            ans[next] = max(ans[next], ans[cur] + D[next]);
            if(--indgree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        memset(ans, 0, sizeof(ans));
        memset(indgree, 0, sizeof(indgree));
        for(int i = 0; i < 1001; i++) adj[i].clear();

        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> D[i];
        }
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indgree[b]++;
        }
        cin >> w;
        topologySort();
        cout << ans[w] << '\n';
    }

    
    return 0;
}