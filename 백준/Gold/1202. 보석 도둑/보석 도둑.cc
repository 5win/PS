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

int n, k;
long long ans;
int C[300001];
pair<int, int> jew[300001];

void solve() {
    priority_queue<int> pq;

    int jIdx = 0;
    for(int i = 0; i < k; i++) {
        int curC = C[i];
        while(jIdx < n) {
            if(jew[jIdx].first <= curC) 
                pq.push(jew[jIdx].second);
            else break;
            jIdx++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    int m, v;
    for(int i = 0; i < n; i++) {
        cin >> m >> v;
        jew[i] = {m, v};
    }
    for(int i = 0; i < k; i++) {
        cin >> C[i];
    }

    sort(jew, jew + n);
    sort(C, C + k);
    solve();

    cout << ans << '\n';

    return 0;
}