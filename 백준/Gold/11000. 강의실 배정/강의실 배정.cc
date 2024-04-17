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

int n;
vector<pair<int, int>> lec;
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    FASTIO;

    cin >> n;
    int a, b;
    while(n--) {
        cin >> a >> b;
        lec.push_back({a, b});
    }
    sort(lec.begin(), lec.end());

    int ans = 0;
    for(auto& i : lec) {
        while(!pq.empty() && pq.top() <= i.first)
            pq.pop();
        pq.push(i.second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << '\n';

    return 0;
}