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

vector<int> lec[10001];

int main(void) {
    FASTIO;

    int n, p, d, maxDate = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p >> d;
        lec[d].push_back(p);
        maxDate = max(maxDate, d);
    }

    int ans = 0;
    priority_queue<int> pq;
    for(int i = maxDate; i > 0; i--) {
        for(int j = 0; j < lec[i].size(); j++)
            pq.push(lec[i][j]);
        if(!pq.empty()) {
            ans += pq.top(); 
            pq.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}