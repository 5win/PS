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

int n, k;
vector<pair<int, int>> adj[100001];
vector<int> dist(100001, INF);

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, n});
    dist[n] = 0;

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
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    for(int i = 0; i <= 100000; i++) {
        if(i - 1 >= 0)
            adj[i].push_back({i - 1, 1});
        if(i + 1 <= 100000)
            adj[i].push_back({i + 1, 1});
        if(i * 2 <= 100000)
            adj[i].push_back({i * 2, 0});
    }
    dijkstra();
    cout << dist[k] << '\n';

    return 0;
}