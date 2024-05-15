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

int n, h;
int minCnt = INF;
int topDown[500002], bottomUp[500002];

void prefixSum() {
    for(int i = h; i > 0; i--) {
        topDown[i] += topDown[i + 1];
    }
    for(int i = 1; i <= h; i++) {
        bottomUp[i] += bottomUp[i - 1];
    }
}

int main(void) {
    FASTIO;

    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if(i % 2 == 0) {
            bottomUp[h - input + 1]++; 
        } else {
            topDown[input]++;
        }
    }
    prefixSum();

    for(int i = 1; i <= h; i++) {
        int cnt = topDown[i] + bottomUp[i];
        minCnt = min(minCnt, cnt);
    }

    int res = 0;
    for(int i = 1; i <= h; i++) {
        int cnt = topDown[i] + bottomUp[i];
        if(cnt == minCnt) {
            res++;
        }
    }
    cout << minCnt << ' ' << res << '\n';


    return 0;
}