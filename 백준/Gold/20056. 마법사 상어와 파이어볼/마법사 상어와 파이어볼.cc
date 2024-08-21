#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Fire {
	int y, x, m, s, d;
};

int n, M, k;
vector<Fire> board[51][51];

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1,};

void move() {
	vector<Fire> tmp[51][51];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j].size() == 0) continue;
			vector<Fire>& cur = board[i][j];
			for(int f = 0; f < cur.size(); f++) {
				int ny = cur[f].y, nx = cur[f].x;
				int dir = cur[f].d;
				int goCnt = cur[f].s % n;
				for(int t = 0; t < goCnt; t++) {
					ny += dy[dir];
					if(ny < 0) ny = n - 1;
					else if(ny >= n) ny = 0;

					nx += dx[dir];
					if(nx < 0) nx = n - 1;
					else if(nx >= n) nx = 0;
				}
				tmp[ny][nx].push_back({ny, nx, cur[f].m, cur[f].s, dir});
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			board[i][j] = tmp[i][j];
}

void splitFire() {
	vector<Fire> tmp[51][51];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j].size() == 0) continue;

			else if(board[i][j].size() == 1) {
				tmp[i][j].push_back(board[i][j][0]);
				continue;
			}
			int mSum = 0, sSum = 0, evenCnt = 0;
			vector<Fire>& cur = board[i][j];
			for(int f = 0; f < cur.size(); f++) {
				mSum += cur[f].m;
				sSum += cur[f].s;
				if(cur[f].d % 2 == 0) evenCnt++;
			}

			int nm = mSum / 5;
			int ns = sSum / cur.size();
			int dir = (evenCnt == 0 || evenCnt == cur.size()) ? 0 : 1;
			if(nm == 0) continue;
			
			for(int f = 0; f < 4; f++) {
				tmp[i][j].push_back({i, j, nm, ns, dir + (f * 2)});
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			board[i][j] = tmp[i][j];
}

int calcMSum() {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int f = 0; f < board[i][j].size(); f++) {
				sum += board[i][j][f].m;
			}
		}
	}
	return sum;
}

int solve() {
	while(k--) {
		move();
		splitFire();
	}	
	return calcMSum();
}

int main(void) {
    FASTIO;

	cin >> n >> M >> k;
	for(int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		board[r - 1][c - 1].push_back({r - 1, c - 1, m, s, d});
	}

	cout << solve() << '\n';

    return 0;
}