#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Fish {
	int num, dir, y, x;
	bool isDead = false;
};

const int SHARK = 20;
int res = 0;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool inRange(int y, int x) {
	return 0 <= y && y < 4 && 0 <= x && x < 4;
}

void moveFish(int board[4][4], vector<Fish>& fish) {
	for(int f = 0; f < 16; f++) {
		if(fish[f].isDead) continue;
		int y = fish[f].y, x = fish[f].x;
		int dir = fish[f].dir;

		for(int i = 0; i < 8; i++) {
			int ny = y + dy[(dir + i) % 8], nx = x + dx[(dir + i) % 8];
			if(!inRange(ny, nx) || board[ny][nx] == SHARK) continue;
			fish[f].dir = (dir + i) % 8;
			fish[f].y = ny;
			fish[f].x = nx;
			if(board[ny][nx] == -1) {
				board[ny][nx] = f;
				board[y][x] = -1;
			} else {
				int nextFNum = board[ny][nx];
				fish[nextFNum].y = y;
				fish[nextFNum].x = x;
				swap(board[y][x], board[ny][nx]);
			}
			break;
		}
	}
}

void dfs(Fish shark, int sum, int board[4][4], vector<Fish> fish) {
	moveFish(board, fish);

	int y = shark.y, x = shark.x;
	int dir = shark.dir;
	for(int i = 1; i <= 4; i++) {
		int ny = y + dy[dir] * i, nx = x + dx[dir] * i;
		if(!inRange(ny, nx) || board[ny][nx] == -1) continue;

		int fNum = board[ny][nx];
		fish[fNum].isDead = true;
		board[ny][nx] = SHARK;
		board[y][x] = -1;

		int tmp[4][4];
		for(int r = 0; r < 4; r++)
			for(int c = 0; c < 4; c++)
				tmp[r][c] = board[r][c];
		dfs({SHARK, fish[fNum].dir, ny, nx}, sum + fNum + 1, tmp, fish);
		board[ny][nx] = fNum;
		board[y][x] = SHARK;
		fish[fNum].isDead = false;
	}

	res = max(res, sum);
}

void solve(int board[4][4], vector<Fish> fish) {

	int firstFish = board[0][0];
	fish[firstFish].isDead = true;
	int sum = fish[firstFish].num + 1;
	Fish shark = {SHARK, fish[firstFish].dir, 0, 0};
	board[0][0] = SHARK;

	dfs(shark, sum, board, fish);
}

bool comp(Fish& a, Fish& b) {
	return a.num < b.num;
}

int main(void) {
    FASTIO;
	
	vector<Fish> fish;
	int board[4][4];
	memset(board, -1, sizeof(board));

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			num--; dir--;
			board[i][j] = num;
			fish.push_back({num, dir, i, j});
		}
	}
	sort(fish.begin(), fish.end(), comp);

	solve(board, fish);
	cout << res << '\n';

    return 0;
}