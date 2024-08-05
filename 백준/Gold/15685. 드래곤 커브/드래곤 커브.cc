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

pair<int, int> drawDragon(int y, int x, int d, int g) {
	if(g == 0) {
		int ny = y + dy[d], nx = x + dx[d];
		board[y][x] = board[ny][nx] = true;
		return {ny, nx};
	}

	pair<int, int> dst = drawDragon(y, x, d, g - 1);
	int ny = dst.first + (x - dst.second);
	int nx = dst.second + -(y - dst.first);
	drawDragon(ny, nx, (d - 1 + 4) % 4, g - 1);
	return {ny, nx};
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		drawDragon(y, x, d, g);
	}
	cout << calcCnt() << '\n';

    return 0;
}