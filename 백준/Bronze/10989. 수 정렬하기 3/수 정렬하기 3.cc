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

    int n, tmp;
    int cnt[10001] = {0, };
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        cnt[tmp]++;
    }
    for(int i = 1; i <= 10000; i++) {
        while(cnt[i]--)
            cout << i << '\n';
    }


    return 0;
}