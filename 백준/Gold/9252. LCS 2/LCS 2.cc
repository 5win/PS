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

    if(cnt == 0) {
        return 0;
    }

    stack<char> st;
    int bound = s2.size();
    for(int i = s1.size(); i > 0; i--) {
        for(int j = 1; j <= bound; j++) {
            if(trace[i][j] == cnt) {
                cnt--;
                bound = j - 1;
                st.push(s1[i - 1]);
            }
            if(cnt == 0) break;
        }
        if(cnt == 0) break;
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }


    return 0;
}