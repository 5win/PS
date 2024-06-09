#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<numeric>

#define endl '\n'

using namespace std;
const int INF = 1987654321;
const int MAX = 1000 * 1000 * 10;
const int _MOD = 1000000007;

int n;
int m;
vector< pair<int, int> > adj[1002];
vector<int> route(1002, INF);

vector<int> dijkstra(int src) {
    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, src));
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    route[src] = src;

    while(!pq.empty()) {
        int curCost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < curCost) continue;

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int nextCost = curCost + adj[cur][i].second;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
                route[next] = cur;
            }
        }
    }
    return dist;
}

vector<int> shortestPath(int dst) {
    vector<int> ret;
    int idx = dst;
    while(route[idx] != idx) {
        ret.push_back(idx);
        idx = route[idx];
    }
    ret.push_back(idx);
    return ret;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   

    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    int src, dst;
    cin >> src >> dst;

    vector<int> ret = dijkstra(src);
    vector<int> path = shortestPath(dst);

    cout << ret[dst] << endl;
    cout << path.size() << endl;
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';

    return 0;
}