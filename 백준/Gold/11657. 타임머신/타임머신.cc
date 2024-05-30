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
// const int INF = 1e9;
const long long INF = 1e12;
const int MOD = 1000000007;
const int MAX_V = 501;

int n, m;
vector<long long> upper(MAX_V, INF);
vector<pair<int, int>> adj[MAX_V];

bool bellmanFord(int start) {
    upper[start] = 0;
    bool isRelax;

    for(int iter = 1; iter <= n; iter++) {
        isRelax = false;
        for(int here = 1; here <= n; here++) {
            for(int i = 0; i < adj[here].size(); i++) {
                int next = adj[here][i].first;
                long long nextCost = upper[here] + adj[here][i].second;
                if(upper[here] != INF && nextCost < upper[next]) {
                    isRelax = true;
                    upper[next] = nextCost;
                }
            }
        }
        if(!isRelax) break;
    }
    return !isRelax;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    bool notExistMinusCycle = bellmanFord(1);
    if(!notExistMinusCycle) {
        cout << "-1\n";
    } else {
        const long long MIN_MINUS_SUM = 4e10;
        for(int i = 2; i <= n; i++) {
            if(upper[i] < INF - MIN_MINUS_SUM)
                cout << upper[i] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}