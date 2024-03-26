#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>

using namespace std;

int f;
vector<int> parent(200001);
vector<int> setSize(200001, 1);
map<string, int> m;

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
    setSize[v] = setSize[u] + setSize[v];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> f;

        // 초기화
        m.clear();
        for(int i = 0; i < 200001; i++) {
            parent[i] = i;
            setSize[i] = 1;
        }

        string s1, s2;
        int mIdx = 0;
        for(int i = 0; i < f; i++) {
            cin >> s1 >> s2;
            if(m.find(s1) == m.end())
                m[s1] = mIdx++;
            if(m.find(s2) == m.end())
                m[s2] = mIdx++;
            // union 
            merge(m[s1], m[s2]);
            cout << setSize[find(m[s1])] << '\n';
        }
    }
    return 0;
}