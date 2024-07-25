#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m;
int maxLen;
int tree[1000001];

bool decision(int x) {
    LL sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (tree[i] >= x) ? tree[i] - x : 0; 
    }
    return sum >= m;
}

int binarySearch() {
    int lo = 0, hi = maxLen + 1;

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

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
        maxLen = max(maxLen, tree[i]);
    }

    cout << binarySearch() << '\n';
    
    return 0;
}