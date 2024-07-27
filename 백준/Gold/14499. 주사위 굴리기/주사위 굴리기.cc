#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m, x, y, k;
int board[21][21];
int dice[4][4];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

void rollLeft() {
	int tmp = dice[1][0];
	for(int i = 0; i < 3; i++) {
		dice[1][i] = dice[1][i + 1];
	}
	dice[3][1] = dice[1][3] = tmp;
}

void rollRight() {
	int tmp = dice[1][3];
	for(int i = 3; i > 0; i--) {
		dice[1][i] = dice[1][i - 1];
	}
	dice[1][0] = tmp;
	dice[3][1] = dice[1][3];
}

void rollUp() {
	int tmp = dice[0][1];
	for(int i = 0; i < 3; i++) {
		dice[i][1] = dice[i + 1][1];
	}
	dice[3][1] = dice[1][3] = tmp;
}

void rollDown() {
	int tmp = dice[3][1];
	for(int i = 3; i > 0; i--) {
		dice[i][1] = dice[i - 1][1];
	}
	dice[0][1] = tmp;
	dice[1][3] = dice[3][1];
}

int main(void) {
    FASTIO;

	cin >> n >> m >> y >> x >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	for(int i = 0; i < k; i++) {
		int dir; cin >> dir;
		dir--;
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if(!inRange(ny, nx)) continue;
		y = ny;
		x = nx;
		switch(dir) {
			case 0:
				rollRight();
				break;
			case 1:
				rollLeft();
				break;
			case 2:
				rollUp();
				break;
			case 3:
				rollDown();
				break;
		}
		if(board[y][x] == 0)
			board[y][x] = dice[1][3];
		else {
			dice[1][3] = dice[3][1] = board[y][x];
			board[y][x] = 0;
		}

		cout << dice[1][1] << '\n';
	}

    return 0;
}