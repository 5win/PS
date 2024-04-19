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

int parent[10001];
vector<pair<int, int>> lec;

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(void) {
    FASTIO;

    int n, p, d;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p >> d;
        lec.push_back({p, d});
    }
    sort(lec.begin(), lec.end(), comp);
    for(int i = 0; i <= 10000; i++)
        parent[i] = i;

    int ans = 0;
    for(int i = 0; i < lec.size(); i++) {
        if(!find(lec[i].second)) continue;
        merge(find(lec[i].second), find(lec[i].second) - 1);
        ans += lec[i].first;
    }
    cout << ans << '\n';

    return 0;
}