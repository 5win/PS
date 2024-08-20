#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m, energy;;
int board[21][21], mBoard[21][21];
vector<int> dBoard[21][21];

pair<int, int> taxi;
int visited[21][21];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	if(get<0>(a) == get<0>(b)) {
		if(get<1>(a) == get<1>(b)) {
			return get<2>(a) < get<2>(b);	
		} else {
			return get<1>(a) < get<1>(b);
		}
	} else {
		return get<0>(a) < get<0>(b);
	}
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({r, c});

	memset(visited, -1, sizeof(visited));
	visited[r][c] = 0;

	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int y = cur.first, x = cur.second;
		for(int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(!inRange(ny, nx) || board[ny][nx] == 1 || visited[ny][nx] != -1) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

int goMember() {
	vector<tuple<int, int, int>> target;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(visited[i][j] != -1 && mBoard[i][j] != 0) {
				target.push_back({visited[i][j], i, j});
			}
		}
	}

	if(target.size() == 0) return -1;

	sort(target.begin(), target.end(), comp);

	int cost = get<0>(target[0]);
	int y = get<1>(target[0]);
	int x = get<2>(target[0]);

	// cout << energy << ", " << cost << '\n';

	if(energy >= cost) {
		energy -= cost;
		int mNum = mBoard[y][x];
		taxi = {y, x};
		mBoard[y][x] = 0;
		return mNum;
	} else {
		return -1;
	}
}

bool goDst(int mNum) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(dBoard[i][j].size() > 0 && visited[i][j] != -1) {
				bool exist = false;
				for(int k = 0; k < dBoard[i][j].size(); k++) {
					if(dBoard[i][j][k] == mNum) {
						dBoard[i][j][k] = 0;
						exist = true;
						break;
					}
				}
				if(!exist) continue;

				if(energy >= visited[i][j]) {
					energy -= visited[i][j];
					taxi = {i, j};
					// dBoard[i][j] = 0;

					energy += visited[i][j] * 2;
					return true;
				} else {
					return false;
				}
			}
		}
	}
	return false;
}

bool memberExist() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			if(mBoard[i][j] > 0) return true;
	}
	return false;
}

void print() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << mBoard[i][j];
		cout << '\n';
	}
	cout << '\n';
}

int solve() {

	// while(true) {
	for(int i = 0; i < m; i++) {
		bfs(taxi.first, taxi.second);
		int mNum = goMember();

		if(mNum == -1) {
			return -1;
			// if(memberExist()) return -1;
			// return energy;
		}

		bfs(taxi.first, taxi.second);

		// for(int r = 0; r < n; r++) {
		// 	for(int c = 0; c < n; c++)
		// 		cout << dBoard[r][c];
		// 	cout << endl;
		// }
		// 	cout << endl;

		// print();
		if(!goDst(mNum)) return -1;
	}
	return energy;
}

int main(void) {
    FASTIO;

	cin >> n >> m >> energy;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cin >> taxi.first >> taxi.second;
	taxi.first--;
	taxi.second--;
	for(int i = 1; i <= m; i++) {
		int y, x;
		cin >> y >> x;
		mBoard[y - 1][x - 1] = i;	
		cin >> y >> x;
		dBoard[y - 1][x - 1].push_back(i);
	}

	cout << solve() << '\n';

    return 0;
}