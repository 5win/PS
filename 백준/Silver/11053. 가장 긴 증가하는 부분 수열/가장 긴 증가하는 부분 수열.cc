#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n; 
int arr[1001];
int dp[1001];

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        int mx = -1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = max(1, mx + 1);
    }
    
    int res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, dp[i]);
    cout << res << endl;

    return 0;
}