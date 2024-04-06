#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m;
int minK;
vector<int> cost;

bool decision(int k) {
    int cnt = 0;
    int remain = 0;
    for(int i = 0; i < n; i++) {
        if(remain < cost[i]) {
            remain = k;   // 남은 돈은 통장에 그대로 넣으므로 대입.
            cnt++;
        }
        remain -= cost[i];
    }
    return m >= cnt;
}

int binarySearch() {
    int lo = minK - 1, hi = 1e9;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if(decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cost.push_back(tmp);
        minK = max(minK, tmp);
    }
    cout << binarySearch() << '\n';

    return 0;
}