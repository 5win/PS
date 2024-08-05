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
bool board[101][101];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int calcCnt() {
	int cnt = 0;
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			if(board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
				cnt++;
		}
	}
	return cnt;
}

void solve(int x, int y, int d, int g) {
	board[y][x] = true;
	y += dy[d];
	x += dx[d];
	board[y][x] = true;

	vector<int> route;
	route.push_back(d);

	for(int i = 1; i <= g; i++) {
		for(int j = route.size() - 1; j >= 0; j--) {
			int dir = (route[j] + 1) % 4;
			y += dy[dir];
			x += dx[dir];
			board[y][x] = true;
			route.push_back(dir);
		}	
	}
}


int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		solve(x, y, d, g);
	}
	cout << calcCnt() << '\n';

    return 0;
}