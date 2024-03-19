#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int house[1001][3];
int dp[1001][3];

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> house[i][j];
        }
    }

    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = house[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;


    return 0;
}