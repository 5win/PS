#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Shark {
	int num, dir, y, x;
	bool isDead = false;
};

int n, m, k;
pair<int, int> board[21][21];
vector<Shark> sharks;
int pri[401][4][4];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool comp(Shark& a, Shark& b) {
	return a.num < b.num;
}

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void moveShark() {
	pair<int, int> tmp[21][21];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tmp[i][j] = board[i][j];

	for(int s = 0; s < sharks.size(); s++) {
		if(sharks[s].isDead) {
			continue;
		}

		int y = sharks[s].y, x = sharks[s].x;
		int dir = sharks[s].dir;

		bool isGone = false;
		for(int d = 0; d < 4; d++) {
			int ndir = pri[s][dir][d];
			int ny = y + dy[ndir], nx = x + dx[ndir];
			if(!inRange(ny, nx) || board[ny][nx].first != -1) continue;
			isGone = true;

			int tmpNum = tmp[ny][nx].first;
			if(tmpNum != -1) {
				sharks[s].isDead = true;
				break;
			} else {
				tmp[ny][nx] = {s, k};
				sharks[s].y = ny;
				sharks[s].x = nx;
				sharks[s].dir = ndir;
				break;
			}
		}
		if(!isGone) {
			for(int d = 0; d < 4; d++) {
				int ndir = pri[s][dir][d];
				int ny = y + dy[ndir], nx = x + dx[ndir];

				if(!inRange(ny, nx) || board[ny][nx].first != s) continue;
				
				if(tmp[ny][nx].first != s) {
					sharks[s].isDead = true;
					break;
				} else {
					tmp[ny][nx] = {s, k};			
					sharks[s].y = ny;
					sharks[s].x = nx;
					sharks[s].dir = ndir;
					break;
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			board[i][j] = tmp[i][j];
}

void subtractTime() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j].first == -1) continue;
			board[i][j].second--;
			if(board[i][j].second == 0)
				board[i][j] = {-1, 0};
		}
	}
	for(int i = 0; i < sharks.size(); i++) {
		if(sharks[i].isDead) continue;
		board[sharks[i].y][sharks[i].x].second = k;
	}
}

bool isEnd() {
	for(int i = 1; i < sharks.size(); i++) {
		if(!sharks[i].isDead) return false;
	}
	return true;
}

int solve() {
	int t = 0;
	while(++t <= 1000) {
		moveShark();
		subtractTime();

		if(isEnd()) {
			return t;
		}
	}
	return -1;
}

int main(void) {
    FASTIO;

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int num; cin >> num;
			num--;
			if(num == -1) {
				board[i][j] = {-1, 0};
			} else {
				board[i][j] = {num, k};
				sharks.push_back({num, 0, i, j});
			}
		}
	}

	sort(sharks.begin(), sharks.end(), comp);
	for(int i = 0; i < m; i++) {
		cin >> sharks[i].dir;
		sharks[i].dir--;
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < 4; j++) {
			for(int l = 0; l < 4; l++) {
				cin >> pri[i][j][l];
				pri[i][j][l]--;
			}
		}
	}

	cout << solve() << '\n';

    return 0;
}