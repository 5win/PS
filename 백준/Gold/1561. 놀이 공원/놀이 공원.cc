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
int minVal = INF;
vector<int> arr;

bool decision(LL x) {
    LL sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += x / arr[i];
        if(x % arr[i]) sum++;
    }
    return n > sum;
}

LL parametricSearch() {
    LL lo = 1, hi = (LL)minVal * n + 1;

    while(lo + 1 < hi) {
        LL mid = (lo + hi) / 2;
        if(decision(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main(void) {
    FASTIO;
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
        minVal = min(minVal, tmp);
    }

    if(n <= m) {
        cout << n << '\n';
        return 0;
    }

    LL prevX = parametricSearch();

    vector<pair<LL, int>> v;
    LL sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        LL people = prevX / arr[i];
        sum += people;
        if(prevX % arr[i]) {
            sum++;
            v.push_back({(people + 1) * arr[i], i + 1});
        } else {
            v.push_back({people * arr[i], i + 1});
        }
    }
    sort(v.begin(), v.end());
    cout << v[n - sum - 1].second << '\n';

    return 0;
}