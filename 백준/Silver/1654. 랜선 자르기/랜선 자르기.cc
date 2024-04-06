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

int k, n;
vector<int> lan;

bool solve(int h) {
    int cnt = 0;
    for(auto& i : lan) {
        cnt += i / h;
    }
    return n <= cnt;
}

int binarySearch() {
    long long lo = 1, hi = 2L << 30;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(solve(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main(void) {
    FASTIO;

    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        lan.push_back(tmp);
    }
    cout << binarySearch() << '\n';

    return 0;
}