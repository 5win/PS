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

int arr[11];
int psum[11];

int main(void) {
    FASTIO;

    for(int i = 1; i <= 10; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    int res = -1;
    int minGap = INF;
    for(int i = 1; i <= 10; i++) {
        if(abs(psum[i] - 100) <= minGap) {
            res = i;
            minGap = abs(psum[i] - 100);
        }
    }
    cout << psum[res] << '\n';

    return 0;
}