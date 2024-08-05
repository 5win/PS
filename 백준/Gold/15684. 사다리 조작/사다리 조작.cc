#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m, h;
int res = INF;
bool line[31][11];

bool check() {

	for(int i = 0; i < n; i++) {
		int curLine = i;
		for(int j = 0; j < h; j++) {
			if(line[j][curLine]) {
				curLine++;
			} else if(curLine > 0 && line[j][curLine - 1]) {
				curLine--;
			}
		}
		if(curLine != i) return false;
	}
	return true;
}

void dfs(int here, int cnt) {
	if(check()) {
		res = min(res, cnt);
	}

	if(cnt == 3) {
		return;
	}
	
	for(int i = here; i < (n - 1) * h; i++) {
		int nextN = (i % (n - 1));
		int nextH = (i / (n - 1));
		if(line[nextH][nextN]) continue;
		if(nextN > 0 && line[nextH][nextN - 1]) continue;
		if(nextN < n - 1 && line[nextH][nextN + 1]) continue;
		line[nextH][nextN] = true;
		dfs(i, cnt + 1);
		line[nextH][nextN] = false;
	}
}

int main(void) {
    FASTIO;

	cin >> n >> m >> h;
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		line[a - 1][b - 1] = true;
	}
	dfs(0, 0);
	if(res == INF) 
		cout << -1 <<'\n';
	else
		cout << res << '\n';

    return 0;
}