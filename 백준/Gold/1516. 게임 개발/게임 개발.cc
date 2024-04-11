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
int T[501], indgree[501], delay[501];
vector<int> adj[501];

void topologySort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
            delay[i] = T[i];
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            delay[next] = max(delay[next], delay[cur] + T[next]);
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
        int tmp;
        while(true) {
            cin >> tmp;
            if(tmp == -1) break;
            adj[tmp].push_back(i);
            indgree[i]++;
        }
    }
    topologySort();
    for(int i = 1; i <= n; i++)
        cout << delay[i] << '\n';
    
    return 0;
}