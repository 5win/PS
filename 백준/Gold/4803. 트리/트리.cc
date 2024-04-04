#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
vector<int> parent(501);

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

    int t = 1;
    while(true) {
        cin >> n >> m;
        if(!n && !m) break;
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            
            int pu = find(u), pv = find(v);
            if(pu == pv || !pu || !pv) {
                parent[pu] = 0;
                parent[pv] = 0;
                continue;
            }
            merge(u, v);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(parent[i] == i) cnt++;
        
        if(cnt == 0)
            cout << "Case " << t << ": No trees.\n";
        else if(cnt == 1)
            cout << "Case " << t << ": There is one tree.\n";
        else
            cout << "Case " << t << ": A forest of " << cnt << " trees.\n";
        
        t++;
    }

    return 0;
}   