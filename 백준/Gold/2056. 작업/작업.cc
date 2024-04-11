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

int n;
int T[10001], indgree[10001], ans[10001];
vector<int> adj[10001];

void topologySort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
            ans[i] = T[i];
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            ans[next] = max(ans[next], ans[cur] + T[next]);
            if(--indgree[next] == 0)
                q.push(next);
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> T[i];
        int m; cin >> m;
        indgree[i] += m;
        for(int j = 0; j < m; j++) {
            int post; cin >> post;
            adj[post].push_back(i);
        }
    }
    topologySort();
    
    int maxAns = 0;
    for(int i = 1; i <= n; i++) {
        maxAns = max(maxAns, ans[i]);
    }
    cout << maxAns << '\n';

    return 0;
}