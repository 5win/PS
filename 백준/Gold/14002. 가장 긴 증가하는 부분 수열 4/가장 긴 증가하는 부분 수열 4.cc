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
int trace[1001];

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++) {
        int mx = 0, prevIdx = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j] > mx) {
                mx = dp[j];
                prevIdx = j;
            }
        }
        if(mx > 0) {
            dp[i] = mx + 1;
            trace[i] = prevIdx;
        }
        else {
            dp[i] = 1;
            trace[i] = i;
        }
    }

    int res = 0;
    int idx = 0;
    vector<int> path;
    for(int i = 0; i < n; i++) {
        if(res < dp[i]) {
            res = dp[i];
            idx = i;
        }
    }
    cout << res << endl;

    // path.push_back(arr[idx]);
    while(idx != trace[idx]) {
        // cout << arr[trace[idx]] << ' ';
        path.push_back(arr[idx]);
        idx = trace[idx];
    }
    path.push_back(arr[idx]);
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';
    
    return 0;
}