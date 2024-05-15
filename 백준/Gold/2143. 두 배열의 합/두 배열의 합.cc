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

int t, n, m;
int arr1[1001], arr2[1001];
int psum1[1001], psum2[1001];

map<int, int> pmap;

void prefixSum() {
    for(int i = 1; i <= n; i++) {
        psum1[i] = psum1[i - 1] + arr1[i];
    }
    for(int i = 1; i <= m; i++) {
        psum2[i] = psum2[i - 1] + arr2[i];
    }
}

int main(void) {
    FASTIO;

    cin >> t;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> arr2[i];
    }

    prefixSum();

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            pmap[t - (psum1[j] - psum1[i - 1])]++;
        }
    }

    long long cnt = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            cnt += pmap[psum2[j] - psum2[i - 1]];
        }
    }
    cout << cnt << '\n';

    return 0;
}