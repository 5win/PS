#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Unit {
	int num;
	int dir;
	int y, x;
};

int n, k;
int board[13][13];
vector<int> game[13][13];
vector<Unit> seq;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void move(Unit& cur, int ny, int nx, bool isRed) {
	vector<int> tmp;
	vector<int>& point = game[cur.y][cur.x];
	bool moving = false;
	for(int i = 0; i < point.size(); i++) {
		if(point[i] == cur.num) {
			moving = true;
		}
		if(moving) {
			tmp.push_back(point[i]);
			seq[point[i]].y = ny;
			seq[point[i]].x = nx;
		}
	}
	
	int tmpSize = tmp.size();
	if(isRed) {
		for(int i = tmpSize - 1; i >= 0; i--) {
			game[ny][nx].push_back(tmp[i]);
		}
	} else {
		for(int i = 0; i < tmpSize; i++) {
			game[ny][nx].push_back(tmp[i]);
		}
	}

	while(tmpSize--)
		point.pop_back();
}

int solve() {
	int turn = 0;

	while(++turn <= 1000) {
		for(auto& cur : seq) {
			int ny = cur.y + dy[cur.dir], nx = cur.x + dx[cur.dir];
			if(!inRange(ny, nx) || board[ny][nx] == 2) {
				cur.dir = (cur.dir % 2 == 0) ? cur.dir + 1 : cur.dir - 1;	
				ny = cur.y + dy[cur.dir], nx = cur.x + dx[cur.dir];

				if(!inRange(ny, nx)) continue;
				if(board[ny][nx] == 0) {
					move(cur, ny, nx, false);
				} else if(board[ny][nx] == 1) {
					move(cur, ny, nx, true);
				}
			}

			else if(board[ny][nx] == 0) {  // white
				move(cur, ny, nx, false);
			}
			else if(board[ny][nx] == 1) { // red
				move(cur, ny, nx, true);
			}

			for(auto& cur : seq) {
				if(game[cur.y][cur.x].size() >= 4) return turn;
			}
		}
	}
	return -1;
}

int main(void) {
    FASTIO;

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for(int i = 0; i < k; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		r--; c--;
		Unit unit = {i, dir - 1, r, c};
		game[r][c].push_back(i);
		seq.push_back(unit);
	}
	cout << solve() << '\n';

    return 0;
}