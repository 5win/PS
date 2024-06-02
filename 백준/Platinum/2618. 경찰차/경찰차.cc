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
const int INF = 1e9;
// const long long INF = 1e13;
const int MOD = 1000000007;
const int MAX = 1000001;

int n, w;
int cache[1001][1001];
vector<pair<int, int>> issue;

int calcDist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int dfs(int p1, int p2) {
    int cur = max(p1, p2);
    if(cur == w) {
        return 0;
    } 

    pair<int, int> curIssue = issue[cur];
    int& ret = cache[p1][p2];
    if(ret != -1)
        return ret;

    int mn = INF;
    pair<int, int> here = p1 == 0 ? make_pair(1, 1) : issue[p1];
    pair<int, int> next = issue[cur + 1];
    mn = min(mn, dfs(cur + 1, p2) + calcDist(here.first, here.second, next.first, next.second));
    here = p2 == 0 ? make_pair(n, n) : issue[p2];
    mn = min(mn, dfs(p1, cur + 1) + calcDist(here.first, here.second, next.first, next.second));

    return ret = mn;
}

void trace(int p1, int p2) {
    int cur = max(p1, p2);
    if(cur == w) return;

    pair<int, int> here = p1 == 0 ? make_pair(1, 1) : issue[p1];
    pair<int, int> next = issue[cur + 1];
    int select_p1 = cache[cur + 1][p2] + calcDist(here.first, here.second, next.first, next.second);
    here = p2 == 0 ? make_pair(n ,n) : issue[p2];
    int select_p2 = cache[p1][cur + 1] + calcDist(here.first, here.second, next.first, next.second);

    if(select_p1 < select_p2) {
        cout << "1\n";
        trace(cur + 1, p2);
    } else {
        cout << "2\n";
        trace(p1, cur + 1);
    }
}

int main(void) {
    FASTIO;

    memset(cache, -1, sizeof(cache));
    cin >> n >> w;
    issue.push_back({0, 0});
    for(int i = 0; i < w; i++) {
        int y, x; cin >> y >> x;
        issue.push_back({y, x});
    }

    int res = dfs(0, 0);
    cout << res << '\n';
    trace(0, 0);

    return 0;
}