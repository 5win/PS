#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int r, c, t;
int board[51][51];
vector<pair<int, int>> cleaner;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < r && 0 <= x && x < c;
}

void spread() {

	int tmp[51][51] = {0, };
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			int cnt = 0;
			int spreadDust = board[i][j] / 5;
			for(int dir = 0; dir < 4; dir++) {
				int ny = i + dy[dir], nx = j + dx[dir];
				if(!inRange(ny, nx) || cleaner[0] == make_pair(ny, nx) || cleaner[1] == make_pair(ny, nx)) continue;
				cnt++;
				tmp[ny][nx] += spreadDust;
			}
			tmp[i][j] += (board[i][j] - spreadDust * cnt);
		}
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			board[i][j] = tmp[i][j];
		}
	}	
}

void cleanClockwise() {
	int y = cleaner[0].first, x = 0;
	for(int i = y; i > 0; i--)
		board[i][x] = board[i - 1][x];	
	board[y][x] = 0;

	for(int j = 0; j < c - 1; j++)
		board[0][j] = board[0][j + 1];
	
	for(int i = 0; i < y; i++) 
		board[i][c - 1] = board[i + 1][c - 1];

	for(int j = c - 1; j > 0; j--) 
		board[y][j] = board[y][j - 1];
}

void cleanClock() {
	int y = cleaner[1].first, x = 0;
	for(int i = y; i < r - 1; i++)
		board[i][x] = board[i + 1][x];
	board[y][x] = 0;

	for(int j = 0; j < c - 1; j++)
		board[r - 1][j] = board[r - 1][j + 1];

	for(int i = r - 1; i > y; i--)
		board[i][c - 1] = board[i - 1][c - 1];
	
	for(int j = c - 1; j > 0; j--)
		board[y][j] = board[y][j - 1];
}

int calcSum() {
	int sum = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}

int solve() {
	while(t--) {
		spread();
		cleanClock();
		cleanClockwise();
	}
	return calcSum();
}

int main(void) {
    FASTIO;

	cin >> r >> c >> t;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> board[i][j];
			if(board[i][j] == -1) {
				cleaner.push_back({i, j});
				board[i][j] = 0;
			}
		}
	}
	cout << solve() << '\n';

    return 0;
}