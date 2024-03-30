#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, c;
vector<int> arr;


bool canPlace(int dist) {
    int cnt = 1;
    int prev = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] - prev >= dist) {
            cnt++;
            prev = arr[i];
        }
        if(cnt >= c) return true;
    }
    return false;
}

int binarySearch() {

    int ret = 0;
    int lo = 0, hi = 1000000000;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(canPlace(mid)) {
            ret = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ret;
}

int main(void) {
    FASTIO;

    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    cout << binarySearch() << '\n';

    return 0;
}