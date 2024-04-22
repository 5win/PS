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

int n;
int parent[200001];
pair<int, int> cup[200001];

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
    int d, v, maxD = 0;
    for(int i = 0; i < n; i++) {
        cin >> d >> v;
        cup[i] = {v, d};
    }
    for(int i = 0; i < 200001; i++)
        parent[i] = i;
    sort(cup, cup + n);

    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        int nextDate = find(cup[i].second);
        if(nextDate == 0) continue;
        ans += cup[i].first;
        merge(nextDate, nextDate - 1);
    }
    cout << ans << '\n';
    
    return 0;
}