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
const int MAX_V = 100001;

int n, k;
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

        if(here + 1 < MAX_V && dist[here + 1] > cost + 1) {
            dist[here + 1] = cost + 1;
            pq.push({cost + 1, here + 1});
        }
        if(0 <= here - 1 && dist[here - 1] > cost + 1) {
            dist[here - 1] = cost + 1;
            pq.push({cost + 1, here - 1}); 
        }
        if(here * 2 < MAX_V && dist[here * 2] > cost) {
            dist[here * 2] = cost;
            pq.push({cost, here * 2});
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    dijkstra();
    cout << dist[k] << '\n';

    return 0;
}