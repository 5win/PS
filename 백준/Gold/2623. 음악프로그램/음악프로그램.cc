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
int indgree[1001];
vector<int> adj[1001];
vector<int> ans;

void topologySort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if(--indgree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        int a, b;
        cin >> a;
        for(int j = 0; j < k - 1; j++) {
            cin >> b;
            adj[a].push_back(b);
            indgree[b]++;
            a = b;
        }
    }
    topologySort();
    if(ans.size() == n)
        for(auto& i : ans) cout << i << '\n';
    else
        cout << "0\n"; 

    return 0;
}