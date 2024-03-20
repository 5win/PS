#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[100001];
int dp[100001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];


    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }
    
    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << '\n';
    }

    return 0;
}