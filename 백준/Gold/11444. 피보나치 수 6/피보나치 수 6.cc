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
#define ULL unsigned long long

const int INF = 1987654321;
const int MOD = 1000000007;

ULL n;
map<ULL, ULL> m;

ULL divide(ULL x) {
    if(x < 0) return 0;
    if(m[x]) return m[x];

    ULL ret;
    if(x % 2) {
        ULL ret1 = divide((x + 1) / 2) % MOD;
        ULL ret2 = divide((x - 1) / 2) % MOD;
        ret = (ret1 * ret1) % MOD + (ret2 * ret2) % MOD;
    } else {
        ret = (divide(x / 2) * ((divide(x / 2 + 1) + divide(x / 2 - 1)) % MOD)) % MOD;
    }
    return m[x] = ret % MOD;
}

int main(void) {
    FASTIO;

    /*
        F(n) = F(n/2+1) * F(n/2) + F(n/2) * F(n/2-1)
            = F(n/2) * (F(n/2-1) + F(n/2 + 1))
    */

    cin >> n;
    m[0] = 0; m[1] = 1; m[2] = 1;
    cout << divide(n) << '\n'; 


    return 0;
}