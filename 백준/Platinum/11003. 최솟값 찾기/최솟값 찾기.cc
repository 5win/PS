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

    int n, l, input;
    cin >> n >> l;

    deque<pair<int, int>> dq;
    for(int i = 1; i <= n; i++) {
        cin >> input;
        while(!dq.empty() && dq.front().second < i - l + 1)
            dq.pop_front();
        while(!dq.empty() && dq.back().first > input)
            dq.pop_back();
        dq.push_back({input, i}); 
        cout << dq.front().first << ' ';
    }

    return 0;
}