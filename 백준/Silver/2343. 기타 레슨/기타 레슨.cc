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
int mx;
vector<int> lec;

bool decision(int x) {

    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < lec.size(); i++) {
        if(sum + lec[i] <= x)
            sum += lec[i];
        else {
            // cout << lec[i] << endl;
            sum = lec[i];
            cnt++;
        }
    }
    if(sum <= x) cnt++;
    // cout << cnt << endl;

    return m >= cnt;
}

int binarySearch() {
    int lo = mx - 1, hi = 1e9;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        // cout << lo << ", " << mid << ", " << hi << '\n';
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
        lec.push_back(tmp);
        mx = max(mx, tmp);
    }
    cout << binarySearch() << '\n';

    return 0;
}