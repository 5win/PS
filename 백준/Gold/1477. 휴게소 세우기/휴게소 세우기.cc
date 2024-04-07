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

int n, m, l;
vector<int> loc;

bool decision(int x) {
    int cnt = 0;
    for(int i = 1; i < loc.size(); i++) {
        cnt += (loc[i] - loc[i - 1]) / x;
        if((loc[i] - loc[i - 1]) % x == 0)
            cnt--;
    }
    return m >= cnt;
}

int parametricSearch() {
    int lo = 0, hi = l;

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
    cin >> n >> m >> l;
    
    loc.push_back(0);
    loc.push_back(l);
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        loc.push_back(tmp);
    }
    sort(loc.begin(), loc.end());
    cout << parametricSearch() << '\n';

    return 0;
}