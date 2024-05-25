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

int n, m;
int whoKnow[51];
int parent[51];

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[v] = u;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;

    int knowCnt; cin >> knowCnt;
    for(int i = 0; i < knowCnt; i++)
        cin >> whoKnow[i];
    for(int i = 1; i < knowCnt; i++)
        merge(whoKnow[i - 1], whoKnow[i]);

    vector<vector<int>> party;
    for(int i = 0; i < m; i++) {
        int partyCnt; cin >> partyCnt;
        vector<int> people;
        while(partyCnt--) {
            int tmp; cin >> tmp;
            people.push_back(tmp);
        }
        for(int j = 1; j < people.size(); j++) {
            merge(people[j - 1], people[j]);
        }
        party.push_back(people);
    }

    if(knowCnt == 0) {
        cout << party.size() << '\n';
    } else {
        int res = 0;
        int knowPerson = find(whoKnow[0]);
        for(auto& p : party) {
            int cnt = 0;
            for(auto& person: p) {
                if(find(person) != knowPerson)
                    cnt++;
            }
            if(cnt == p.size()) res++;
        }
        cout << res << '\n';
    }

    return 0;
}