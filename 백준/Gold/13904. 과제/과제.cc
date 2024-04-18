#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int main(void) {
    FASTIO;

    int n, d, w, maxDate = 0;
    vector<int> assign[1001];
    priority_queue<int> pq;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> d >> w;
        assign[d].push_back(w);
        maxDate = max(maxDate, d);
    }

    int ans = 0;
    for(int i = maxDate; i > 0; i--) {
        for(int j = 0; j < assign[i].size(); j++)
            pq.push(assign[i][j]);
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}