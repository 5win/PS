#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;

int v, e, k;
int dist[20001];
vector<pair<int, int>> adj[20001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        int cost = cur.first;
        int here = cur.second;
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> v >> e >> k;
    fill(dist, dist + v + 1, INF);
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra();
    for(int i = 1; i <= v; i++) {
        if(dist[i] >= INF)  cout << "INF\n";
        else                cout << dist[i] << '\n';
    }    

    return 0;
}