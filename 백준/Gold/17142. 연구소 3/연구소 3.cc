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
int board[51][51];
int visited[51][51];
int res = INF;
vector<pair<int, int>> virus;
vector<pair<int, int>> selected;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void bfs() {
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	
	for(auto& v : selected) {
		q.push(v);
		visited[v.first][v.second] = 0;
	}

	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int y = cur.first, x = cur.second;

		for(int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];

			if(!inRange(ny, nx) || visited[ny][nx] != -1 || board[ny][nx] == 1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

int calcTime() {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 0 && visited[i][j] == -1) return -1;
			if(board[i][j] == 0 && visited[i][j] != -1) {
				ret = max(ret, visited[i][j]);
			}
		}
	}
	return ret;
}

void dfs(int here, int cnt) {
	if(cnt == m) {
		bfs();
		int t = calcTime();
		t = (t == -1) ? INF : t;
		res = min(res, t);
		return;
	}
	
	for(int next = here + 1; next < virus.size(); next++) {
		selected.push_back(virus[next]);
		dfs(next, cnt + 1);
		selected.pop_back();
	}
}

int main(void) {
    FASTIO;


	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
			if(board[i][j] == 2) {
				virus.push_back({i, j});
			}
		}
	}
	dfs(-1, 0);

	res = (res == INF) ? -1 : res;
	cout << res << '\n';

    return 0;
}