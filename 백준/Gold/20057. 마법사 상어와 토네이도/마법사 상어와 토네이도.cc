#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Tonado {
	int y, x, dir;
};

int n;
int board[500][500];
bool visited[500][500];
Tonado tonado;
int outAmount = 0;

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void moveTonado() {
	tonado.y += dy[tonado.dir];
	tonado.x += dx[tonado.dir];
	visited[tonado.y][tonado.x] = true;
}

void spread() {
	int y = tonado.y, x = tonado.x;
	int dir = tonado.dir;
	int amount = board[y][x];
	int rest = board[y][x];

	// up
	int nDir = (dir - 2 + 8) % 8;
	int ny = y + dy[nDir], nx = x + dx[nDir];
	int cost = (amount * 7) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	ny = y + 2 * dy[nDir]; nx = x + 2 * dx[nDir];
	cost = (amount * 2) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// down
	nDir = (dir + 2) % 8; 
	ny = y + dy[nDir]; nx = x + dx[nDir];
	cost = (amount * 7) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	ny = y + 2 * dy[nDir]; nx = x + 2 * dx[nDir];
	cost = (amount * 2) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// rightUp
	nDir = (dir - 3 + 8) % 8; 
	ny = y + dy[nDir]; nx = x + dx[nDir];
	cost = amount / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// rightDown
	nDir = (dir + 3) % 8; 
	ny = y + dy[nDir]; nx = x + dx[nDir];
	cost = amount / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// leftUp
	nDir = (dir - 1 + 8) % 8; 
	ny = y + dy[nDir]; nx = x + dx[nDir];
	cost = (amount * 10) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// leftDown
	nDir = (dir + 1) % 8; 
	ny = y + dy[nDir]; nx = x + dx[nDir];
	cost = (amount * 10) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// straight (5%)
	nDir = dir; 
	ny = y + 2 * dy[nDir]; nx = x + 2 * dx[nDir];
	cost = (amount * 5) / 100;
	if(inRange(ny, nx)) {
		board[ny][nx] += cost;
	} else {
		outAmount += cost;
	}
	rest -= cost;

	// a
	nDir = dir; 
	ny = y + dy[nDir]; nx = x + dx[nDir];
	if(inRange(ny, nx)) {
		board[ny][nx] += rest;
	} else {
		outAmount += rest;
	}

	// remove cur
	board[y][x] = 0;
}

void solve() {
	int dist = 1;
	int& y = tonado.y;
	int& x = tonado.x;
	int& dir = tonado.dir;
	while(y != 0 || x != 0) {
		moveTonado();
		spread();

		int leftDir = (dir + 2) % 8;
		if(!visited[y + dy[leftDir]][x + dx[leftDir]]) {
			dir = leftDir;
		}
	}

}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	tonado = {n / 2, n / 2, 4};
	visited[n / 2][n / 2] = true;

	solve();
	cout << outAmount << '\n';

    return 0;
}