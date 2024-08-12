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
	bool isVertical;
	int speed;
	int dir;
	int size;
};

int r, c, m;
int board[102][102];
int res = 0;
vector<Shark> sharks;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x) {
	return 1 <= y && y <= r && 1 <= x && x <= c;
}

void catchShark(int col) {
	for(int i = 1; i <= r; i++) {
		int sharkNum = board[i][col];
		if(sharkNum == -1) continue;
		res += sharks[sharkNum].size;
		board[i][col] = -1;
		break;
	}
}

void moveShark() {
	int tmp[102][102];
	memset(tmp, -1, sizeof(tmp));

	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			int sharkNum = board[i][j];
			if(sharkNum == -1) continue;

			int y = i, x = j;
			Shark &cur = sharks[sharkNum];
			int moveCnt = (cur.isVertical) ? cur.speed % (r * 2 - 2) : cur.speed % (c * 2 - 2);
			// int roundCnt = (cur.isVertical) ? cur.speed / r : cur.speed / c;

			// 방향 전환
			// if(roundCnt % 2 == 1)
			// 	cur.dir = (cur.dir % 2 == 0) ? cur.dir + 1 : cur.dir - 1;

			for(int cnt = 0; cnt < moveCnt; cnt++) {
				int ny = y + dy[cur.dir], nx = x + dx[cur.dir];
				if(!inRange(ny, nx)) {
					cur.dir = (cur.dir % 2 == 0) ? cur.dir + 1 : cur.dir - 1;
					ny = y + dy[cur.dir];
					nx = x + dx[cur.dir];
				}
				y = ny;
				x = nx;
			}
			if(tmp[y][x] == -1) {
				tmp[y][x] = sharkNum;
			} else if(sharks[tmp[y][x]].size < cur.size) {
				tmp[y][x] = sharkNum;
			}
		}
	}

	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			board[i][j] = tmp[i][j];
}

void solve() {

	for(int cur = 1; cur <= c; cur++) {
		catchShark(cur);
		moveShark();
	}
}

int main(void) {
    FASTIO;

	memset(board, -1, sizeof(board));

	cin >> r >> c >> m;
	for(int i = 0; i < m; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		d--;
		if(d < 2)
			sharks.push_back({true, s, d, z});	
		else 
			sharks.push_back({false, s, d, z});	
		board[y][x] = i;
	}
	solve();
	cout << res << '\n';

    return 0;
}