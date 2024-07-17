#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int m, n;
int maxLen;
int snack[1000001];

bool decision(int len) {
    int cnt = 0;
    for(auto& i : snack) {
        cnt += i / len;
    }
    return cnt >= m;
}

int binarySearch() {
    int lo = 1, hi = maxLen + 1;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main(void) {
    FASTIO;

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> snack[i];
        maxLen = max(maxLen, snack[i]);
    }

    if(accumulate(snack, snack + n, 0) < m)
        cout << "0\n";
    else
        cout << binarySearch() << '\n';

    
    return 0;
}