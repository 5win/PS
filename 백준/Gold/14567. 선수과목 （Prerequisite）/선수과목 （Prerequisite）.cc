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
int indgree[1001], ans[1001];
vector<int> adj[1001];

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
            int next = adj[cur][i];
            if(--indgree[next] == 0) {
                ans[next] = ans[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        indgree[b]++;
    }
    topologySort();
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}