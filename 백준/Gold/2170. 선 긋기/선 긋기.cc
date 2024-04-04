#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n;
vector<pair<int, int>> arr;

void solve() {
    int s = arr[0].first, e = arr[0].second;

    int sum = 0;
    for(int i = 1; i < n; i++) {
        pair<int, int> cur = arr[i];
        if(e < cur.first) {
            sum += e - s;
            s = cur.first;
            e = cur.second;
        } else {
            e = max(e, cur.second);
        }
    }
    sum += e - s;
    cout << sum << '\n';
}

int main(void) {
    FASTIO;

    cin >> n;
    int s, e;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        arr.push_back({s, e});
    }
    sort(arr.begin(), arr.end());
    solve();

    return 0;
}   