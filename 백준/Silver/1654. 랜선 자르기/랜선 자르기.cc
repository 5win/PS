#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, k;
int maxLen;
int lan[10001];

bool optimize(int len) {
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        cnt += lan[i] / len;
    }
    return cnt >= n;
}

int parametric() {
    LL lo = 1, hi = (LL)maxLen + 1;

    while(lo + 1 < hi) {
        LL mid = (lo + hi) / 2;
        if(optimize(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main(void) {
    FASTIO;

    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        cin >> lan[i];
        maxLen = max(maxLen, lan[i]);
    }
    cout << parametric() << '\n';
    
    return 0;
}