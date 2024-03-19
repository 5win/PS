#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<numeric>

#define endl '\n'

using namespace std;
const int INF = 1987654321;
const int MAX = 1000 * 1000 * 10;
const int _MOD = 1000000007;

int n;
int dp[14];

int solve(int sum) {
    if(sum > n) return 0;
    if(sum == n) return 1;
    int ret = 0;
    for(int i = 1; i <= 3; i++) {
        ret += solve(sum + i);
    }
    return ret;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << solve(0) << endl;
    }

    return 0;
}