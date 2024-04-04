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

    int s = v[0].first, e = v[0].second;
    for(int i = 1; i < v.size(); i++) {
        pair<int, int> cur = v[i];
        if(e < cur.first) {
            sum += (e - s) * 2;
            s = cur.first;
            e = cur.second;
        } else {
            e = max(e, cur.second);
        }
    }
    sum += (e - s) * 2;
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
            v.push_back({e, s});
        }
    }
    sort(v.begin(), v.end());
    solve();

    return 0;
}   