#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n;
vector<int> dp;
vector<int> arr(1000001);

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    dp.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        int target = arr[i];
        if(dp.back() < target) {
            dp.push_back(target);
        } else {
            auto iter = lower_bound(dp.begin(), dp.end(), target);
            dp[iter - dp.begin()] = target;
        }
    }
    cout << dp.size() << '\n';

    return 0;
}