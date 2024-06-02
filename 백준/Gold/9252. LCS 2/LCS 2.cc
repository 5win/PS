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

// const int INF = 1987654321;
const int INF = 1e9;
// const long long INF = 1e13;
const int MOD = 1000000007;
const int MAX = 1000001;

int dp[1001][1001];
int trace[1001][1001];

int main(void) {
    FASTIO;

    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                trace[i][j] = dp[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int cnt = dp[s1.size()][s2.size()];
    cout << cnt << '\n';

    stack<char> st;
    int r = s1.size(), c = s2.size();
    while(cnt != 0) {
        int cur = dp[r][c];
        if(dp[r - 1][c] == cur) {
            r--; continue;
        } else if(dp[r][c - 1] == cur) {
            c--; continue;
        } else {
            st.push(s1[r - 1]);
            r--; c--;
            cnt--;
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }


    return 0;
}