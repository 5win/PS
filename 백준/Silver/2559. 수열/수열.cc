#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, k;
int arr[100001];
int psum[100001];

int main(void) {
    FASTIO;

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 0; i <= n; i++)
        psum[i] = psum[i - 1] + arr[i];

    int res = -INF;
    for(int i = 1; i <= n - k + 1; i++) {
        res = max(res, psum[i + k - 1] - psum[i - 1]);
    }    
    cout << res << endl;

    return 0;
}