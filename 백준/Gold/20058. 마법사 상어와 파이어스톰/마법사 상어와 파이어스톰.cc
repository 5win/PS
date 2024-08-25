#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, q, m;
int ice[65][65];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < m && 0 <= x && x < m;
}

void rotate(int y, int x, int l) {
	int tmp[65][65];
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) {
			tmp[y + j][x + l - 1 - i] = ice[y + i][x + j];
		}
	}

	for(int i = 0; i < l; i++)
		for(int j = 0; j < l; j++)
			ice[y + i][x + j] = tmp[y + i][x + j];
}

int bfs() {
	queue<pair<int, int>> q;
	bool visited[65][65] = {false, };

	int ret = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			if(visited[i][j] || ice[i][j] == 0) continue;
			visited[i][j] = true;
			q.push({i, j});
			int sum = 1;

			while(!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				int y = cur.first, x = cur.second;
				for(int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir], nx = x + dx[dir];
					if(!inRange(ny, nx) || visited[ny][nx] || ice[ny][nx] == 0) continue;
					visited[ny][nx] = true;
					sum++;
					q.push({ny, nx});
				}
			}
			ret = max(ret, sum);
		}
	}
	return ret;
}

void subtractIce() {
	int tmp[65][65];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			tmp[i][j] = ice[i][j];

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			if(ice[i][j] == 0) continue;

			int cnt = 0;
			for(int dir = 0; dir < 4; dir++) {
				int ny = i + dy[dir], nx = j + dx[dir];
				if(!inRange(ny, nx)) continue;
				if(ice[ny][nx] > 0) cnt++;
			}
			if(cnt < 3)
				tmp[i][j]--;
		}
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			ice[i][j] = tmp[i][j];
}

void print() {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++)
			cout << ice[i][j];
		cout << '\n';
	}
		cout << '\n';
}

void solve(int l) {

	int grid = (1 << l);

	for(int i = 0; i < m; i += grid) {
		for(int j = 0; j < m; j += grid) {
			rotate(i, j, grid);
		}
	}
	subtractIce();
}

int calcSum() {
	int sum = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			sum += ice[i][j];
		}
	}
	return sum;
}

int main(void) {
    FASTIO;

	cin >> n >> q;
	m = (1 << n);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}

	for(int i = 0; i < q; i++) {
		int l; cin >> l;
		solve(l);
	}
	cout << calcSum() << '\n';
	cout << bfs() << '\n';


    return 0;
}