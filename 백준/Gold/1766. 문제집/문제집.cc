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

int n, m;
int indgree[32001];
vector<int> adj[32001];

void topologySort() {
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
        if(!indgree[i])
            pq.push(-i);
    }

    while(!pq.empty()) {
        int cur = -pq.top();
        pq.pop();
        cout << cur << ' ';

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if(--indgree[next] == 0) {
                pq.push(-next);
            }
        }
    }
}

int main(void) {
    FASTIO;
    
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        indgree[b]++;
    }
    topologySort();

    return 0;
}