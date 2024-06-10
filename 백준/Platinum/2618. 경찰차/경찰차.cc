#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n, w;

int dp[1001][1001];
vector<pair<int, int>> task;

int calcDist(pair<int, int> p, pair<int, int> t) {
    return abs(p.first - t.first) + abs(p.second - t.second);
}

int dfs(int p1, int p2, int taskNum) {

    if(taskNum > w) {
        return 0;
    }

    int &ret = dp[p1][p2];
    if(ret != -1)
        return ret;

    pair<int, int> p1Loc = p1 == 0 ? make_pair(1, 1) : task[p1];
    pair<int, int> p2Loc = p2 == 0 ? make_pair(n, n) : task[p2];

    int dist = calcDist(p1Loc, task[taskNum]);
    ret = dfs(taskNum, p2, taskNum + 1) + dist;

    dist = calcDist(p2Loc, task[taskNum]);
    ret = min(ret, dfs(p1, taskNum, taskNum + 1) + dist);

    return ret;
}

void trace(int p1, int p2, int taskNum) {
    if(taskNum > w) return;

    pair<int, int> p1Loc = p1 == 0 ? make_pair(1, 1) : task[p1];
    pair<int, int> p2Loc = p2 == 0 ? make_pair(n, n) : task[p2];

    int dist1 = calcDist(p1Loc, task[taskNum]) + dp[taskNum][p2];
    int dist2 = calcDist(p2Loc, task[taskNum]) + dp[p1][taskNum];

    if(dist1 < dist2) {
        cout << "1\n";
        trace(taskNum, p2, taskNum + 1);
    } else {
        cout << "2\n";
        trace(p1, taskNum, taskNum + 1);
    }

}

int main(void) {
    FASTIO;

    cin >> n >> w;
    task.push_back({0, 0});     //dummy
    for(int i = 0; i < w; i++) {
        int a, b; cin >> a >> b;
        task.push_back({a, b});
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 1) << '\n';
    trace(0, 0, 1);
    
    return 0;
}