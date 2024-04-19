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

int g, p;
int parent[100001];

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

    cin >> g >> p;
    for(int i = 1; i <= 1e5; i++) parent[i] = i;

    int plane, ans = 0;
    bool finish = false;
    for(int i = 0; i < p; i++) {
        cin >> plane;
        if(finish) continue;

        int gate = find(plane);
        if(gate == 0) break;
        // if(gate == 0) {
        //     finish = true;
        //     continue;
        // }
        merge(gate, gate - 1);
        ans++;
    }
    cout << ans << '\n';

    return 0;
}