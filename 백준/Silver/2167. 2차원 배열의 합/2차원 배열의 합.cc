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

int n, m, k;
int arr[301][301];
int psum[301][301];

void preSum() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            psum[i][j] = arr[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
}

int main(void) {
    FASTIO;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    preSum();

    cin >> k;
    while(k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << psum[x][y] - psum[i - 1][y] - psum[x][j - 1] + psum[i - 1][j - 1] << '\n';
    }

    return 0;
}