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
int d, s;
int y, x;
int board[51][51];
int cnt[5];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

bool inRange(int cy, int cx) {
	return 0 <= cy && cy < n && 0 <= cx && cx < n;
}

void destroyBall() {
	int ny = y, nx = x;
	for(int i = 0; i < s; i++) {
		ny += dy[d];
		nx += dx[d];
		if(!inRange(ny, nx)) break;
		board[ny][nx] = 0;
	}
}

void move() {
	int dir = 0;
	int ny = y, nx = x;

	vector<int> nums;
	int amount = 1;
	while(inRange(ny, nx)) {
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			else if(board[ny][nx] != 0)
				nums.push_back(board[ny][nx]);
		}
		dir = (dir + 1) % 4;
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			else if(board[ny][nx] != 0)
				nums.push_back(board[ny][nx]);
		}
		dir = (dir + 1) % 4;
		amount++;
	}
	
	// for(int i = 0; i < n; i++) {
	// 	for(int j  =0; j < n; j++)
	// 		cout << tmp[i][j] << ' ';
	// 	cout << endl;
	// }
	// 	cout << endl;

	dir = 0;
	ny = y; nx = x;
	amount = 1;
	int idx = 0;
	memset(board, 0, sizeof(board));
	while(inRange(ny, nx)) {
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			else if(idx < nums.size())
				board[ny][nx] = nums[idx++];
		}
		dir = (dir + 1) % 4;
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			else if(idx < nums.size())
				board[ny][nx] = nums[idx++];
		}
		dir = (dir + 1) % 4;
		amount++;
	}
}

bool boom() {
	bool isBoom = false;
	int dir = 0;
	int ny = y, nx = x;
	int prev = -1;

	vector<pair<int, int>> nums;
	int amount = 1;
	while(inRange(ny, nx)) {
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			if(board[ny][nx] == prev) {
				nums.push_back({ny, nx});
			} else {
				if(nums.size() >= 4) {
					isBoom = true;
					cnt[board[nums.back().first][nums.back().second]] += nums.size();
					for(auto& num : nums) {
						board[num.first][num.second] = 0;
					}
				}
				if(board[ny][nx] == 0) return isBoom;
				nums.clear();
				nums.push_back({ny, nx});
				prev = board[ny][nx];
			}
		}
		dir = (dir + 1) % 4;
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			if(board[ny][nx] == prev) {
				nums.push_back({ny, nx});
			} else {
				if(nums.size() >= 4) {
					cnt[board[nums.back().first][nums.back().second]] += nums.size();
					isBoom = true;
					for(auto& num : nums) {
						board[num.first][num.second] = 0;
					}
				}
				if(board[ny][nx] == 0) return isBoom;
				nums.clear();
				nums.push_back({ny, nx});
				prev = board[ny][nx];
			}
		}
		dir = (dir + 1) % 4;
		amount++;
	}
	if(nums.size() >= 4) {
		cnt[board[nums.back().first][nums.back().second]] += nums.size();
		isBoom = true;
		for(auto& num : nums) {
			board[num.first][num.second] = 0;
		}
	}
	return isBoom;
}

void expandBall() {
	int dir = 0;
	int ny = y, nx = x;

	vector<int> groups;
	vector<int> nums;
	bool isFinish = false;
	int prev = -1;
	int amount = 1;
	while(inRange(ny, nx) && !isFinish) {
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			if(board[ny][nx] == prev) {
				nums.push_back(prev);
			} else {
				if(nums.size() > 0) {
					groups.push_back(nums.size());
					groups.push_back(nums.back());
				}
				nums.clear();
				prev = board[ny][nx];
				if(prev == 0) {
					isFinish = true;
					break;
				}
				nums.push_back(prev);
			}
		}
		if(isFinish) break;
		dir = (dir + 1) % 4;
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			if(board[ny][nx] == prev) {
				nums.push_back(prev);
			} else {
				if(nums.size() > 0) {
					groups.push_back(nums.size());
					groups.push_back(nums.back());
				}
				nums.clear();
				prev = board[ny][nx];
				if(prev == 0) {
					isFinish = true;
					break;
				}
				nums.push_back(prev);
			}
		}
		dir = (dir + 1) % 4;
		amount++;
	}

	dir = 0;
	ny = y; nx = x;
	amount = 1;
	int idx = 0;
	memset(board, 0, sizeof(board));
	while(inRange(ny, nx)) {
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			else if(idx < groups.size())
				board[ny][nx] = groups[idx++];
		}
		dir = (dir + 1) % 4;
		for(int i = 0; i < amount; i++) {
			ny += dy[dir];
			nx += dx[dir];
			if(!inRange(ny, nx))
				break;
			else if(idx < groups.size())
				board[ny][nx] = groups[idx++];
		}
		dir = (dir + 1) % 4;
		amount++;
	}
}

void print() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void solve() {
	destroyBall();
	move();
	while(boom()) {
		move();
	}
	expandBall();
}

int main(void) {
    FASTIO;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	y = n / 2;
	x = n / 2;

	while(m--) {
		cin >> d >> s;
		if(d == 1) d = 3;
		else if(d == 2) d = 1;
		else if(d == 3) d = 0;
		else d = 2;

		solve();
	}
	cout << cnt[1] + 2 * cnt[2] + 3 * cnt[3] << '\n';


    return 0;
}