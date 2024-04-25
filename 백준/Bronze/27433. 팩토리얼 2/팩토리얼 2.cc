#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n;

int main(void) {
    FASTIO;

    cin >> n;
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
    cout << ans << '\n';
    
    return 0;
}