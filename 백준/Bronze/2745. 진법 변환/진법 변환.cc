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


int main(void) {
    FASTIO;

    string n;
    int b;
    cin >> n >> b;

    int res = 0, div = 1;
    for(int i = n.size() - 1; i >= 0; i--) {
        if('0' <= n[i] && n[i] <= '9') {
            res += (n[i] - '0') * div;
        } else {
            res += (n[i] - 'A' + 10) * div;
        }
        div *= b;
    }
    cout << res << endl;


    return 0;
}