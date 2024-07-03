#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

string code;
int codeLen;
int dp[5001];

int dfs(string &num) {
    int len = num.size();

    if(len >= codeLen) {
        return num == code ? 1 : 0;
    }

    int &ret = dp[len];
    if(ret != -1) return ret;

    int sum = 0;
    for(int i = 1; i <= 26; i++) {
        string nextNum = num + to_string(i);
        if(i < 10 && len + 1 <= codeLen && nextNum == code.substr(0, len + 1)) {
            sum = (sum + dfs(nextNum)) % MOD;
        } else if(len + 2 <= codeLen && nextNum == code.substr(0, len + 2)) {
            sum = (sum + dfs(nextNum)) % MOD;
        }
    }
    return ret = sum;
}

int main(void) {
    FASTIO;

    cin >> code;
    codeLen = code.size();

    memset(dp, -1, sizeof(dp));
    string num = "";
    cout << dfs(num) << '\n';

    return 0;
}