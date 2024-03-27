#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>
#include <math.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 1987654321;

int n;
vector<pair<int, int>> vertex;
vector<pair<int, double>> adj[101];
vector<bool> visited(101, false);
vector<double> minWeight(101, INF);

void calcEdge() {
    for(int i = 0; i < vertex.size(); i++) {
        for(int j = i + 1; j < vertex.size(); j++) {
            double cost = sqrt(pow(vertex[i].first - vertex[j].first, 2) + pow(vertex[i].second - vertex[j].second, 2));
            adj[i].push_back({j, cost});
            adj[j].push_back({i, cost});
        }
    }
}
            
double prim() {

    double ret = 0;

    minWeight[0] = 0;

    for(int iter = 0; iter < n; iter++) {
        int u = -1;         // 다음에 추가할 정점
        for(int i = 0; i < n; i++) {
            // 추가하지 않은 정점이면서 && (첫 정점을 선택하는 경우이거나 || 더 작은 정점이 있는 경우)
            if(!visited[i] && (u == -1 || minWeight[u] > minWeight[i]))
                u = i;
        }
        ret += minWeight[u];
        visited[u] = true;

        for(int i = 0; i < adj[u].size(); i++) {
            int nextV = adj[u][i].first;
            double cost = adj[u][i].second;
            if(visited[nextV] || minWeight[nextV] <= cost) continue;
            minWeight[nextV] = cost;
        }
    }
    return ret;
}

int main(void) {
    FASTIO;

    cin >> n;

    double x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        vertex.push_back({x, y});
    }
    calcEdge();

    cout.precision(3);
    cout << prim() << endl;

    return 0;
}