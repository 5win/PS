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
int n, q;
int parent[200001], level[200001];
vector<int> adj[200001];

bool lca(int u, int v) {
	if(level[u] < level[v]) swap(u, v);
	
	while(level[u] != level[v]) {
		if(u == parent[u]) return false;
		u = parent[u];
	}
	
	while(u != v) {
		if(u == parent[u] || v == parent[v]) return false;
		u = parent[u];
		v = parent[v];
	}
	return u == v;
}

void setTree(int node, int pnode) {
	parent[node] = pnode;
	level[node] = level[pnode] + 1;
	for(int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		setTree(next, node);
	}
}

int main(void) {
    FASTIO;

    cin >> n >> q;
	for(int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
		parent[i] = p;
	}
	setTree(1, 1);
	
	for(int i = 0; i < (n - 1) + q; i++) {
		int x; cin >> x;
		if(x == 0) {
			int b; cin >> b;
			parent[b] = b;
		} else {
			int c, d;
			cin >> c >> d;
			if(lca(c, d)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}


    return 0;
}