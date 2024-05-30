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
// const int INF = 1e9;
const int INF = 6e8;
const int MOD = 1000000007;
const int MAX_V = 2001;

int n, m, t;
int s, g, h;
int distGH;
vector<pair<int, int>> adj[MAX_V];
vector<int> dst;

vector<int> dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(MAX_V, INF);
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

    int T; cin >> T;
    while(T--) {
        cin >> n >> m >> t;
        dst.clear();
        for(int i = 0; i <= n; i++) adj[i].clear();

        cin >> s >> g >> h;
        while(m--) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
            if(a == g && b == h || a == h && b == g)
                distGH = d;
        }
        while(t--) {
            int tmp; cin >> tmp;
            dst.push_back(tmp);
        }
        vector<int> distS = dijkstra(s);
        vector<int> distG = dijkstra(g);
        vector<int> distH = dijkstra(h);

        // s -> g direct h -> dest
        vector<int> resDist(MAX_V);
        int distSGH = distS[g] + distGH;
        for(const auto& i : dst) {
            resDist[i] = distSGH + distH[i];
        }

        // s -> h direct g -> dest
        int distSHG = distS[h] + distGH;
        for(const auto& i : dst) {
            resDist[i] = min(resDist[i], distSHG + distG[i]);
        }

        vector<int> res;
        for(const auto& i : dst) {
            if(distS[i] == resDist[i])
                res.push_back(i); 
        }
        sort(res.begin(), res.end());
        for(const auto& i : res) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}