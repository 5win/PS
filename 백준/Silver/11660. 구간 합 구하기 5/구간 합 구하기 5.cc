#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
int arr[1025][1025];
int psum[1025][1025];

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    // row 0, col 0
    for(int i = 1; i <= n; i++) {
        psum[0][i] = psum[0][i - 1] + arr[0][i];
        psum[i][0] = psum[i - 1][0] + arr[i][0];
    }
    // 나머지 누적 합
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + arr[i][j];
        }
    }
    
    // 부분합 출력
    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}