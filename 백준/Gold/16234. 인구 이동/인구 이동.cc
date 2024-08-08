#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, l, r;
int board[51][51];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void movePeople(vector<pair<int, int>>& v) {
	int sum = 0;
	for(auto& country : v) {
		sum += board[country.first][country.second];
	}
	int num = sum / v.size();
	for(auto& country : v) {
		board[country.first][country.second] = num;
	}
}

bool bfs() {
	bool visited[51][51] = {false, };
	bool isFinish = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(visited[i][j]) continue;	
			queue<pair<int, int>> q;
			vector<pair<int, int>> v;
			q.push({i, j});
			v.push_back({i, j});
			visited[i][j] = true;

			while(!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				int y = cur.first, x = cur.second;
				for(int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir], nx = x + dx[dir];
					if(!inRange(ny, nx) || visited[ny][nx]) continue;

					int diff = abs(board[ny][nx] - board[y][x]);
					if(diff < l || r < diff) continue;

					visited[ny][nx] = true;
					isFinish = false;
					q.push({ny, nx});
					v.push_back({ny, nx});
				}
			}
			movePeople(v);
		}
	}
	return isFinish;
}

int main(void) {
    FASTIO;

	cin >> n >> l >> r;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int res = 0;
	while(!bfs()) {
		res++;
	}
	cout << res << '\n';

    return 0;
}