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
vector<int> parent(500001);

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return false;
    parent[u] = v;
    return true;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        parent[i] = i;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        if(!merge(a, b)) {
            cout << i + 1 << '\n';
            return 0; 
        }
    }
    cout << "0\n";

    return 0;
}