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
const int INF = 6e8;
const int MOD = 1000000007;

int n, e, v1, v2;
vector<pair<int, int>> adj[801];

vector<int> dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(801, INF); 
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return dist;
}

int main(void) {
    FASTIO;

    cin >> n >> e;
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    vector<int> dist1 = dijkstra(1);
    vector<int> distV1 = dijkstra(v1);
    vector<int> distV2 = dijkstra(v2);
    int res = INF;
    // 1 -> v1 -> v2 -> n
    res = min(res, dist1[v1] + distV1[v2] + distV2[n]);
    // 1 -> v2 -> v1 -> n
    res = min(res, dist1[v2] + distV2[v1] + distV1[n]);
    if(res >= INF)  cout << "-1\n";
    else            cout << res << '\n';

    return 0;
}