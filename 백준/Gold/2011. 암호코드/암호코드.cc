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
int dp[5001];

void solve() {

	if('0' < code[0])
		dp[0] = 1;
	if('0' < code[1])
		dp[1] = dp[0];
	int num = stoi(code.substr(0, 2));
	if(10 <= num && num <= 26) {
		dp[1]++;
	}

	for(int i = 2; i < code.size(); i++) {
		if('0' < code[i])
			dp[i] = (dp[i] + dp[i - 1]) % MOD;


		int num = stoi(code.substr(i - 1, 2));
		if(10 <= num && num <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}
}

int main(void) {
    FASTIO;

    cin >> code;
	solve();
	cout << dp[code.size() - 1] << '\n';

    return 0;
}