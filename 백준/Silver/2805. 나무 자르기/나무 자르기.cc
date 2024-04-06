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
vector<int> wood;

bool solve(int h) {
    long long sum = 0;
    for(auto& i : wood) {
        if(i > h)
            sum += i - h;
    }
    return m <= sum;
}

int binarySearch() {
    int lo = 0, hi = 1e9;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(solve(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        wood.push_back(tmp);
    }
    cout << binarySearch() << '\n';

    return 0;
}