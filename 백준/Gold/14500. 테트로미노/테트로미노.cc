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
int board[501][501];
bool visited[501][501];
int res = 0;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int cnt, int y, int x, int sum) {

	if(cnt == 4) {
		res = max(res, sum);
		return;
	}

	int ret = 0;
	for(int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(!inRange(ny, nx) || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		dfs(cnt + 1, ny, nx, sum + board[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main(void) {
    FASTIO;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 마지막 도형 빼고
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(1, i, j, board[i][j]);
			visited[i][j] = false;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int sum = board[i][j];
			for(int dir = 0; dir < 4; dir++) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if(!inRange(ny, nx)) continue;
				sum += board[ny][nx];
			}	

			for(int dir = 0; dir < 4; dir++) {
				res = max(res, sum - board[i + dy[dir]][j + dx[dir]]);
			}
		}
	}
	
	cout << res << '\n';

    return 0;
}