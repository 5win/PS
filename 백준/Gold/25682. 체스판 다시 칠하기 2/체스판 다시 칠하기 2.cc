#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m, k;
string board[2001];

int calcMin(char color) {
    int psum[2001][2001] = {0, };

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int val;
            if((i + j) % 2) {
                val = board[i - 1][j - 1] == color;
            } else {
                val = board[i - 1][j - 1] != color;
            }
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + val;
        }
    }

    int ret = INF;
    for(int i = 0; i <= n - k; i++) {
        for(int j = 0; j <= m - k; j++) {
            ret = min(ret, psum[i + k][j + k] - psum[i + k][j] - psum[i][j + k] + psum[i][j]);
        }
    }
    return ret;
}

int main(void) {
    FASTIO;

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    cout << min(calcMin('B'), calcMin('W')) << '\n';

    return 0;
}