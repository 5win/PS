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
priority_queue<int> pq;

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pq.push(-tmp);
    }
    int ans = 0;
    while(pq.size() > 1) {
        int a = -pq.top(); pq.pop();
        int b = -pq.top(); pq.pop();
        ans += a + b;
        pq.push(-(a + b));
    }
    cout << ans << '\n';

    return 0;
}