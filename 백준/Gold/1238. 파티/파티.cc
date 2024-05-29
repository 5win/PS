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

int n, m, x;
vector<pair<int, int>> adj[1001];
vector<pair<int, int>> radj[1001];

vector<int> dijkstra(vector<pair<int, int>> curAdj[]) {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(1001, INF);
    dist[x] = 0;
    pq.push({0, x});

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        int here = cur.second;
        if(dist[here] < cost) continue;
        for(int i = 0; i < curAdj[here].size(); i++) {
            int next = curAdj[here][i].first;
            int nextDist = cost + curAdj[here][i].second;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    return dist;
}

int main(void) {
    FASTIO;

    cin >> n >> m >> x;
        
    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        adj[s].push_back({e, t});
        radj[e].push_back({s, t});
    }

    vector<int> dist1 = dijkstra(adj);
    vector<int> dist2 = dijkstra(radj);

    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(res, dist1[i] + dist2[i]);
    }
    cout << res << '\n';

    return 0;
}