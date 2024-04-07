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

int m, n;
int maxLen;
vector<int> snack;

bool decision(int x) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += snack[i] / x;
    }
    return m <= cnt;
}

int parametricSearch() {
    int lo = 1, hi = maxLen + 1;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main(void) {
    FASTIO;

    long long sum = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        snack.push_back(tmp);
        maxLen = max(maxLen, tmp);
        sum += tmp;
    }
    if(sum < m)
        cout << "0\n";
    else
        cout << parametricSearch() << '\n';

    return 0;
}