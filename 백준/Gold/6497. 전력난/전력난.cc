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

struct EDGE {
    int x, y, w;
    // bool operator<(EDGE& a) const {
    //     if(w != a.w) return w < a.w;
    //     if(x != a.x) return x < a.x;
    //     return y < a.y;
    // }
};

bool comp(EDGE &a, EDGE &b) {
        if(a.w != b.w) return a.w < b.w;
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
}

int n, m;
vector<int> parent(200001);
vector<EDGE> edges;

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

    while(true) {
        edges.clear();
        cin >> m >> n;
        if(!m && !n) break;

        for(int i = 0; i < m; i++)
            parent[i] = i;

        int x, y, z;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
            sum += z;
        }

        sort(edges.begin(), edges.end(), comp);

        for(auto& e : edges) {
            if(find(e.x) == find(e.y)) continue;
            merge(e.x, e.y);
            sum -= e.w;
        }
        cout << sum << '\n';
    }

    return 0;
}