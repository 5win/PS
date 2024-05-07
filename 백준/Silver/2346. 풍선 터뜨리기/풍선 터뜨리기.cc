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

const int INF = 1987654321;
const int MOD = 1000000007;

int n;
deque<pair<int, int>> dq;

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        dq.push_back({input, i + 1});
    }

    while(dq.size() > 1) {
        pair<int, int> cur = dq.front();
        dq.pop_front();
        cout << cur.second << ' ';

        int size = dq.size();
        int cnt = cur.first < 0 ? abs(cur.first) : cur.first - 1;
        cnt %= size;
        // cout << cnt << ", ";
        cnt = (cur.first < 0) ? size - cnt : cnt;
        // cout << "cnt : " << cnt << '\n';
        for(int i = 0; i < cnt; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    cout << dq.front().second << '\n';


    return 0;
}