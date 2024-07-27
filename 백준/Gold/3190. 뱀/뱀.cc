#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, k, l;
int board[101][101];
map<int, char> turn;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

int solve() {
	deque<pair<int, int>> dq;
	dq.push_front({0, 0});
	board[0][0] = 1;
	int dir = 0;
	int t = 0;
	while(true) {
		if(turn.find(t) != turn.end()) {
			char d = turn[t];
			if(d == 'L')
				dir = (dir + 1) % 4;
			else
				dir = (dir == 0) ? 3 : dir - 1;
		}

		pair<int, int> cur = dq.front();
		int ny = cur.first + dy[dir];
		int nx = cur.second + dx[dir];

		t++;
		if(!inRange(ny, nx) || board[ny][nx] == 1) break;

		dq.push_front({ny, nx});
		if(board[ny][nx] != 2) {
			board[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		board[ny][nx] = 1;
		
	}
	return t;
}

int main(void) {
    FASTIO;

	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		board[y - 1][x - 1] = 2;
	}
	cin >> l;
	for(int i = 0; i < l; i++) {
		int x; char c;
		cin >> x >> c;
		turn[x] = c;
	}

	cout << solve() << '\n';

    return 0;
}