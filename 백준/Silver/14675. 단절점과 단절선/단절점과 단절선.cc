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
int vNum = 1;
bool cutVertex[100001];
int discovered[100001];
vector<int> adj[100001];
vector<pair<int, int>> edge;
map<pair<int, int>, bool> cutEdge;

int findCutVertex(int here, int prev, bool isRoot) {
    discovered[here] = vNum++;
    int ret = discovered[here];
    int children = 0;

    for(int i = 0; i < adj[here].size(); i++) {
        children++;
        int next = adj[here][i];
        if(next == prev) continue;
        if(discovered[next] == -1) {
            int subtree = findCutVertex(next, here, false); 
            ret = min(ret, subtree);
            if(subtree >= discovered[here]) {
                cutVertex[here] = true;
            }
            if(subtree > discovered[here]) {
                cutEdge[{min(here, next), max(here, next)}] = true;
            }
        } else {
            ret = min(ret, discovered[next]);
        }
    }    
    if(isRoot) {
        cutVertex[here] = (children >= 2); 
    }
    return ret;
}

int main(void) {
    FASTIO;
    memset(discovered, -1, sizeof(discovered));

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({min(a, b), max(a, b)});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    findCutVertex(1, 0, true);

    cin >> q;
    while(q--) {
        int t, k;
        cin >> t >> k;
        if(t == 1) {
            if(cutVertex[k]) cout << "yes\n";
            else cout << "no\n";
        } else {
            if(cutEdge[edge[k - 1]]) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}