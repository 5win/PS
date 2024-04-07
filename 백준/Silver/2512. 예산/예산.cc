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
vector<int> req;

bool decision(int up) {
    int sum = 0;
    for(auto& i : req) {
        if(i > up)
            sum += up;
        else
            sum += i;
    }
    return sum <= m;
}

int binarySearch() {
    int lo = 1, hi = maxVal + 1;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main(void) {
    FASTIO;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        req.push_back(tmp);
        maxVal = max(maxVal, tmp);
    }
    cin >> m;
    cout << binarySearch() << endl;

    return 0;
}