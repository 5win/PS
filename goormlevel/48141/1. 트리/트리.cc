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

const int INF = 1987654321;
const int MOD = 1000000007;

struct Query {
    int x, a, b;
};

int n, q;
int parent[200001], tmpParent[200001];
vector<Query> query;

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[v] = u;
}

int main(void) {
    FASTIO;

    cin >> n >> q;
    for(int i =1; i <= n; i++)
        parent[i] = i;
	for(int i = 2; i <= n; i++) {
		int p; cin >> p;
        tmpParent[i] = p;
	}
	
	for(int i = 0; i < (n - 1) + q; i++) {
		int x; cin >> x;
		if(x == 0) {
			int b; cin >> b;
            query.push_back({x, b});
		} else {
			int c, d;
			cin >> c >> d;
            query.push_back({x, c, d});
		}
	}

    stack<string> res;
    for(int i = query.size() - 1; i >= 0; i--) {
        if(query[i].x == 0) {
            int node = query[i].a;
            merge(tmpParent[node], node);
        } else {
            int u = query[i].a, v = query[i].b;
            if(find(u) == find(v))
                res.push("YES\n");
            else
                res.push("NO\n");
        }
    }
    while(!res.empty()) {
        cout << res.top();
        res.pop();
    }

    return 0;
}