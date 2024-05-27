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
int discovered[10001];
bool finished[10001];
bool isCutVertex[10001];
vector<int> adj[10001];

int findCutVertex(int here, bool isRoot) {
    discovered[here] = vNum++;
    int ret = discovered[here];
    int children = 0;
    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(discovered[next] == -1) {
            children++;
            int subtree = findCutVertex(next, false);
            ret = min(ret, subtree);
            if(!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
        } else {
            ret = min(ret, discovered[next]);
        }
    }
    if(isRoot)
        isCutVertex[here] = (children >= 2);
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

    for(int i = 1; i <= n; i++) {
        if(discovered[i] == -1)
            findCutVertex(i, true);
    }
    
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        if(isCutVertex[i]) res.push_back(i);
    }
    cout << res.size() << '\n';
    for(auto& i : res)
        cout << i << ' ';

    return 0;
}