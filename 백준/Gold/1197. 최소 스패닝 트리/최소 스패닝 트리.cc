#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent(10001);

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i <= n; i++)
        parent[i] = i;
    int s, e, c;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> c;
        edges.push_back({c, {s, e}});
    }
    sort(edges.begin(), edges.end());

    int sum = 0;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        int cost = edges[i].first;
        if(find(u) == find(v)) continue;

        merge(u, v);
        sum += cost;
    }
    cout << sum << endl;

    return 0;
}