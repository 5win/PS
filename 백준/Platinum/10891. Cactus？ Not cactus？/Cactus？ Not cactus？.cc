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
int vNum = 0;
int discovered[100001], cycle[100001];
bool finished[100001];
vector<int> adj[100001];
vector<int> path;

void dfs(int here, int prev) {
    discovered[here] = vNum++;
    path.push_back(here);

    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(next == prev) continue;
        if(discovered[next] == -1) {
            dfs(next, here);
        } else if(!finished[next] && discovered[next] < discovered[here]) {
            for(int j = path.size() - 1; j >= 0; j--) {
                cycle[path[j]]++;
                if(path[j] == next) break;
            }
        }
    }
    path.pop_back();
    finished[here] = true;
}

int main(void) {
    FASTIO;
    
    memset(discovered, -1, sizeof(discovered));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    
    for(int i = 1; i <= n; i++) {
        if(cycle[i] >= 2) {
            cout << "Not cactus\n";
            return 0;
        }
    }
    cout << "Cactus\n";

    return 0;
}