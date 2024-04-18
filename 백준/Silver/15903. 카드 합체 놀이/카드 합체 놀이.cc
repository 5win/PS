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

    int n, m;
    priority_queue<long long, vector<long long>, greater<>> pq;
    cin >> n >> m;
    while(n--) {
        long long input; cin >> input;
        pq.push(input);
    }
    while(m--) {
        long long sum;
        sum = pq.top(); pq.pop();
        sum += pq.top(); pq.pop();
        pq.push(sum);
        pq.push(sum);
    }
    long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';

    return 0;
}