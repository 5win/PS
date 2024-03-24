#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int n;
int arr[1001];
int dp[1001];
int trace[1001];

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        trace[i] = -1;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
    }

    int res = 0;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(res < dp[i]) {
            res = dp[i];
            idx = i;
        }
    }
    cout << res << endl;

    stack<int> st;
    while(idx != -1) {
        st.push(arr[idx]);
        idx = trace[idx];
    }
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    
    return 0;
}