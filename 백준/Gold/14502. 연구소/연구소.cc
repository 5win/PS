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
int board[10][10];
bool visited[10][10];
vector<pair<int, int>> virus;
int res;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

void calcMax(int tmp[10][10]) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(tmp[i][j] == 0) cnt++;
		}
	}
	res = max(res, cnt);
}

void bfs() {
	int tmpBoard[10][10];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmpBoard[i][j] = board[i][j];
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	for(auto& i : virus)
		q.push(i);

	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int y = cur.first, x = cur.second;
		for(int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(!inRange(ny, nx) || visited[ny][nx] || tmpBoard[ny][nx] != 0) continue;
			tmpBoard[ny][nx] = 2;
			visited[ny][nx] = true;
			q.push({ny, nx});
		}
	}

	calcMax(tmpBoard);
}

void dfs(int cnt, int cur) {

	if(cnt == 3) {
		bfs();
		return;
	}

	for(int i = cur; i < n * m; i++) {
		int row = i / m;
		int col = i % m;
		if(board[row][col] != 0) continue;

		board[row][col] = 1;
		dfs(cnt + 1, i + 1);
		board[row][col] = 0;
	}
}

int main(void) {
    FASTIO;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == 2)
				virus.push_back({i, j});
		}
	}
	dfs(0, 0);
	cout << res << '\n';

    return 0;
}