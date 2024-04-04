#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
vector<pair<int, int>> v;

void solve() {
    long long sum = 0;
    int cnt = 1;
    int prev = v[0].first;
    for(int i = 1; i < v.size(); i++) {
        pair<int, int> cur = v[i];

        if(cnt == 0)
            prev = cur.first;
        cnt += cur.second;
        if(cnt == 0) 
            sum += (cur.first - prev) * 2;
    }
    sum += m;
    cout << sum << '\n';
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    int s, e;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        if(e < s) {
            v.push_back({e, 1});
            v.push_back({s, -1}); 
        }
    }
    sort(v.begin(), v.end());
    solve();

    return 0;
}   