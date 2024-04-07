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
// int maxT;
vector<int> T;

bool decision(long long x) {
    long long cnt = 0;
    
    for(int i = 0; i < n; i++) {
        cnt += (x / T[i]);
        if(m <= cnt) return true;
    }
    return false;
    // return m <= cnt;
}

long long binarySearch() {
    long long lo = 0, hi = 1e18;

    while(lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        
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
        T.push_back(tmp);
        // maxT = max(maxT, tmp);
    }
    cout << binarySearch() << '\n';

    return 0;
}