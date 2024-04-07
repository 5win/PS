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
int maxVal;
vector<int> arr;

bool decision(int x) {
    if(!x) return false;

    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += arr[i] / x;
        if(arr[i] % x != 0)
            cnt++;
    }
    return n >= cnt;
}

int parametricSearch() {
    int lo = 0, hi = maxVal;

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
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
        maxVal = max(maxVal, tmp);
    }
    cout << parametricSearch() << '\n';

    return 0;
}