#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, t;
int sharkSize = 2;
int eatCnt = 0;
int board[21][21];
pair<int, int> sharkLoc;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void eat(int visited[21][21], int minDist) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] != 0 && board[i][j] < sharkSize && visited[i][j] == minDist) {
				board[i][j] = 0;
				eatCnt++;	
				sharkLoc = {i, j};
				return;
			}
		}
	}
}

bool bfs() {
	int visited[21][21];
	memset(visited, -1, sizeof(visited));

	queue<pair<int, int>> q;
	q.push(sharkLoc);
	visited[sharkLoc.first][sharkLoc.second] = 0;

	int minDist = INF;
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int y = cur.first, x = cur.second;
		for(int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(!inRange(ny, nx) || visited[ny][nx] != -1 || board[ny][nx] > sharkSize) continue;

			visited[ny][nx] = visited[y][x] + 1;
			if(board[ny][nx] != 0 && board[ny][nx] < sharkSize) 
				minDist = min(minDist, visited[ny][nx]);
			q.push({ny, nx});
		}
	}
	if(minDist == INF) return false;
	eat(visited, minDist);
	t += minDist;
	return true;
}

void solve() {
	while(true) {
		if(!bfs()) break;
		if(eatCnt == sharkSize) {
			sharkSize++;
			eatCnt = 0;
		}	
	}
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
			if(board[i][j] == 9) {
				sharkLoc = {i, j};
				board[i][j] = 0;
			}
		}
	}
	solve();
	cout << t << '\n';

    return 0;
}