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
    int mn = INF, mx = 0;
    int cnt = 0;

    for(int i = 0; i < arr.size(); i++) {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
        if(mx - mn > x) {
            cnt++;
            mn = mx = arr[i];
        }
    }
    return m > cnt;
}

int parametricSearch() {
    int lo = -1, hi = maxVal;

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
        arr.push_back(tmp);
        maxVal = max(maxVal, tmp);
    }
    cout << parametricSearch() << '\n';

    return 0;
}