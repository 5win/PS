#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Group {
	int size = 0, rainbow = 0, y, x;
};

int n, m;
int score;
int board[21][21];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool comp(Group& a, Group& b) {
	if(a.size == b.size) {
		if(a.rainbow == b.rainbow) {
			if(a.y == b.y) {
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.rainbow > b.rainbow;
	}
	return a.size > b.size;
}

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

Group bfs(bool visited[21][21], int i, int j, bool remove) {
	queue<pair<int, int>> q;
	q.push({i, j});
	visited[i][j] = true;
	int color = board[i][j];

	Group ret;
	vector<pair<int, int>> yx;

	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int y = cur.first, x = cur. second;

		if(remove) {
			board[y][x] = -2;
		}

		if(board[y][x] == 0) ret.rainbow++;
		else yx.push_back({y, x});
		ret.size++;

		for(int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(!inRange(ny, nx) || visited[ny][nx]) continue;
			if(board[ny][nx] != 0 && board[ny][nx] != color) continue;
			visited[ny][nx] = true;
			q.push({ny, nx});
		}
	}

	sort(yx.begin(), yx.end());
	ret.y = yx[0].first;
	ret.x = yx[0].second;
	return ret;
}

vector<Group> findGroup() {
	vector<Group> ret;
	bool visited[21][21] = {false, };

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			memset(visited, false, sizeof(visited));
			if(visited[i][j] || board[i][j] <= 0) continue;
			Group g = bfs(visited, i, j, false);
			if(g.size > 1)
				ret.push_back(g);
		}
	}
	sort(ret.begin(), ret.end(), comp);
	return ret;
}

void removeBlock(Group target) {
	bool visited[21][21] = {false, };
	bfs(visited, target.y, target.x, true);
	score += target.size * target.size;
}

void gravity() {
	for(int j = 0; j < n; j++) {
		int tmp[21];
		for(int i = 0; i < n; i++)
			tmp[i] = -2;

		int idx = n - 1;
		for(int i = n - 1; i >= 0; i--) {
			if(board[i][j] > -1) {
				tmp[idx--] = board[i][j];
			} else if(board[i][j] == -1) {
				idx = i;
				tmp[idx--] = board[i][j];
			} else {
				continue;
			}
		}

		for(int i = 0; i < n; i++)
			board[i][j] = tmp[i];
	}
}

void rotate() {
	int tmp[21][21];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tmp[n - 1 - j][i] = board[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			board[i][j] = tmp[i][j];
}

void solve() {
	while(true) {
		vector<Group> g = findGroup();
		if(g.size() == 0) {
			break;
		}
		Group target = g[0];
		removeBlock(target);
		gravity();
		rotate();
		gravity();
	}
}

int main(void) {
    FASTIO;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve();
	cout << score << '\n';

    return 0;
}