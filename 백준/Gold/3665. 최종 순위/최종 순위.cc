#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m;
bool adj[501][501];
int indgree[501];
vector<int> prevRank;
vector<int> ans;

void init() {
    for(int i = 0; i < prevRank.size(); i++) {
        for(int j = i + 1; j < prevRank.size(); j++) {
            adj[prevRank[j]][prevRank[i]] = true;
            indgree[prevRank[i]]++;
        }
    }
}

bool topologySort() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) {
            q.push(i);
            indgree[i]--;
        }
    }

    while(!q.empty()) {
        if(q.size() > 1) return false;
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        
        for(int i = 1; i <= n; i++)
            if(adj[cur][i]) indgree[i]--;

        for(int i = 1; i <= n; i++) {
            if(adj[cur][i] && indgree[i] == 0) {
                indgree[i]--;
                q.push(i);
            }
        }
    }
    return true;
}

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        prevRank.clear();
        ans.clear();
        memset(indgree, 0, sizeof(indgree));
        memset(adj, 0, sizeof(adj));

        cin >> n;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            prevRank.push_back(tmp);
        }

        init();

        cin >> m;
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if(adj[a][b]) { // a -> b
                indgree[a]++;
                indgree[b]--;
            } else {        // b -> a
                indgree[a]--;
                indgree[b]++;
            }
            adj[a][b] = !adj[a][b];
            adj[b][a] = !adj[b][a];
        }
        if(topologySort()) {
            bool isImpossible = false;
            for(int i = 1; i <= n; i++) {
                if(indgree[i] > 0) {
                    isImpossible = true;
                    break;
                }
            }
            if(isImpossible) {
                cout << "IMPOSSIBLE\n";
            } else {
                for(int i = ans.size() - 1; i >= 0; i--)
                    cout << ans[i] << ' ';
                cout << '\n';
            }
        } else {
            cout << "?\n";
        }
    }

    return 0;
}