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
int vNum = 1;
int discovered[100001];
int parent[100001];
vector<int> adj[100001], compressedAdj[100001];
vector<pair<int, int>> newEdge;
vector<int> leaf;

int find(int u) {
    // if(u == parent[u]) return u;
    if(!parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[v] = u;
}

int findCutEdge(int here, int prev) {
    discovered[here] = vNum++;
    int ret = discovered[here];
    bool moreThanOne = false;

    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(next == prev && !moreThanOne) {
            moreThanOne = true;
            continue;
        }
        if(discovered[next] == -1) {
            int subtree = findCutEdge(next, here);
            ret = min(ret, subtree);
            if(subtree > discovered[here]) {        // 단절선이면
                newEdge.push_back({here, next});
            } else {
                merge(here, next);
            }
        } else {
            ret = min(ret, discovered[next]);
        }
    }
    return ret;
}

void findLeaf(int here, int prev) {
    if(compressedAdj[here].size() == 1) {
        leaf.push_back(here);
    }
    for(const auto& next : compressedAdj[here]) {
        if(prev == next) continue;
        findLeaf(next, here);
    }
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

    for(int i = 0; i < newEdge.size(); i++) {
        int u = newEdge[i].first, v = newEdge[i].second;
        u = find(u); v = find(v);
        compressedAdj[u].push_back(v);
        compressedAdj[v].push_back(u);
    }    
    findLeaf(1, 0);

    int leafSize = leaf.size();
    cout << (leafSize + 1) / 2 << '\n';
    for(int i = 0; i < leafSize / 2; i++) {
        cout << leaf[i] << ' ' << leaf[i + leafSize / 2] << '\n';
    }
    if(leafSize % 2 == 1) {
        cout << leaf[0] << ' ' << leaf.back() << '\n';
    }

    return 0;
}