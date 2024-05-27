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
int discovered[100001];
vector<int> adj[100001];
vector<pair<int, int>> cutEdge;

int findCutEdge(int here, int prev) {
    discovered[here] = vNum++;
    int ret = discovered[here];
    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(next == prev) continue;

        if(discovered[next] == -1) {
            int subtree = findCutEdge(next, here);
            ret = min(ret, subtree);
            if(subtree > discovered[here]) {
                cutEdge.push_back({min(here, next), max(here, next)});
            }
        } else {
            ret = min(ret, discovered[next]);
        }
    }
    return ret;
}

int main(void) {
    FASTIO;
    
    memset(discovered, -1, sizeof(discovered));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findCutEdge(1, 0);
    sort(cutEdge.begin(), cutEdge.end());
    cout << cutEdge.size() << '\n';
    for(auto& i : cutEdge) {
        cout << i.first << ' ' << i.second << '\n';    
    }

    return 0;
}