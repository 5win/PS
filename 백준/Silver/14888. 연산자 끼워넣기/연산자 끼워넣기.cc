#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n;
int A[12];
int opers[4];
int mn = INF, mx = -INF;

int calculate(vector<int>& expr) {
	int res = A[0];
	for(int i = 1; i < expr.size(); i++) {
		switch(expr[i]) {
			case 0:
				res += A[i];
				break;
			case 1:
				res -= A[i];
				break;
			case 2:
				res *= A[i];
				break;
			case 3:
				res /= A[i];
				break;
		}
	}
	return res;
}

void dfs(int cur, vector<int>& expr) {
	if(cur == n - 1) {
		int res = calculate(expr);
		mn = min(mn, res);
		mx = max(mx, res);
		return;
	}

	for(int i = 0; i < 4; i++) {
		if(opers[i] != 0) {
			opers[i]--;
			expr.push_back(i);
			dfs(cur + 1, expr);
			expr.pop_back();
			opers[i]++;
		}
	}
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < 4; i++)
		cin >> opers[i];

	vector<int> v;
	v.push_back(-1);
	dfs(0, v);
	cout << mx << '\n' << mn << '\n';

    return 0;
}