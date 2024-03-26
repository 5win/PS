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

int n;
vector<pair<double, double>> vertex;
vector<pair<double, pair<double, double>>> edges;
vector<int> parent(101);

void calcEdge() {
    for(int i = 0; i < vertex.size(); i++) {
        for(int j = i + 1; j < vertex.size(); j++) {
            double cost = sqrt(pow(vertex[i].first - vertex[j].first, 2) + pow(vertex[i].second - vertex[j].second, 2));
            edges.push_back({cost, {i, j}});
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

    cin >> n;
    for(int i = 0; i < n; i++)
        parent[i] = i;

    double x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        vertex.push_back({x, y});
    }
    calcEdge();

    sort(edges.begin(), edges.end());

    double sum = 0;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        double cost = edges[i].first;
        if(find(u) == find(v)) continue;
        merge(u, v);
        sum += cost;
    }
    cout.precision(3);
    cout << sum << endl;

    return 0;
}