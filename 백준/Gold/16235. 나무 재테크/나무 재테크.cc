#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m, k;
vector<int> tree[11][11];
int energy[11][11];
int A[11][11];

int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void springAndSummer() {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			sort(tree[r][c].begin(), tree[r][c].end());
			int addEnergy = 0;
			vector<int> tmp;
			for(auto& cost : tree[r][c]) {
				if(cost <= energy[r][c]) {
					energy[r][c] -= cost;
					tmp.push_back(cost + 1);
				} else {
					addEnergy += cost / 2;
				}
			}
			tree[r][c] = tmp;
			energy[r][c] += addEnergy;
		}
	}
}

void autum() {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			for(auto& age : tree[r][c]) {
				if(age % 5 == 0) {
					for(int dir = 0; dir < 8; dir++) {
						int ny = r + dy[dir], nx = c + dx[dir];
						if(!inRange(ny, nx)) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}	
}

void winter() {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			energy[r][c] += A[r][c];
		}
	}
}

int calcLive() {
	int cnt = 0;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			cnt += tree[r][c].size();
		}
	}
	return cnt;
}

int solve() {
	while(k--) {
		springAndSummer();
		autum();
		winter();
	}
	return calcLive();
}

int main(void) {
    FASTIO;

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> A[i][j];
			energy[i][j] = 5;
		}
	}

	for(int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}
	cout << solve() << '\n';

    return 0;
}