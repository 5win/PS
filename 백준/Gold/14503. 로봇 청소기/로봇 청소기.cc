#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m;
int r, c, d;
int board[51][51];
bool visited[51][51];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool existNotCleaned(int y, int x) {
	for(int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if(board[ny][nx] == 0) return true;
	}
	return false;
}

int solve() {

	int y = r, x = c;
	int dir = d;
	int cnt = 0;
	while(true) {

		if(board[y][x] == 0) {
			board[y][x] = -1;
			cnt++;
		}

		if(existNotCleaned(y, x)) {
			dir = (dir - 1 + 4) % 4;
			if(board[y + dy[dir]][x + dx[dir]] == 0) {
				y += dy[dir];
				x += dx[dir];
			}
		} else {
			int rDir = (dir + 2) % 4;
			if(board[y + dy[rDir]][x + dx[rDir]] != 1) {
				y += dy[rDir];
				x += dx[rDir];
			} else {
				break;
			}
		}
	}	
	return cnt;
}

int main(void) {
    FASTIO;

	cin >> n >> m >> r >> c >> d;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cout << solve() << '\n';

    return 0;
}