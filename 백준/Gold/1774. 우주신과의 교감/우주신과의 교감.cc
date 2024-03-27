#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>
#include <math.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 1987654321;

int n, m;
vector<pair<int, int>> vertex;
vector<pair<double, pair<int, int>>> edges;
vector<int> parent(1001);

void calcEdge() {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            double weight = sqrt(pow(vertex[i].first - vertex[j].first, 2) + pow(vertex[i].second - vertex[j].second, 2));
            edges.push_back({weight, {i, j}});
        }
    }
}

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
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertex.push_back({x, y});
        parent[i] = i;
    }
    calcEdge();
    sort(edges.begin(), edges.end());

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        merge(u - 1, v - 1);
    }

    double res = 0;
    for(int i = 0; i < edges.size(); i++) {
        u = edges[i].second.first, v = edges[i].second.second;
        double weight = edges[i].first;
        if(find(u) == find(v)) continue;
        merge(u, v);
        res += weight;
    }
    cout << fixed;
    cout.precision(2);
    cout << res << endl;

    return 0;
}