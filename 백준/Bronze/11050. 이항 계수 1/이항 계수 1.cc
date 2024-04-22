#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int main(void) {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int a = 1, b = 1;
    for(int i = n; i > n - k; i--)
        a *= i;
    for(int i = 1; i <= k; i++)
        b *= i;
    cout << a / b << '\n';
    
    return 0;
}