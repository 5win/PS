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
bool cloud[51][51];
int bucket[51][51];
int d, s;

int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void moveCloud() {
	bool tmp[51][51] = {false, };
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!cloud[i][j]) continue;
			int ny = i, nx = j;
			for(int l = 0; l < s; l++) {
				ny += dy[d];
				if(ny < 0) ny = n - 1;
				else if(ny == n) ny = 0;

				nx += dx[d];
				if(nx < 0) nx = n - 1;
				else if(nx == n) nx = 0;
			}

			tmp[ny][nx] = true;
			bucket[ny][nx]++;
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cloud[i][j] = tmp[i][j];
}

void copyWater() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!cloud[i][j]) continue;

			int cnt = 0;
			for(int dir = 1; dir < 8; dir += 2) {
				int ny = i + dy[dir], nx = j + dx[dir];
				if(!inRange(ny, nx) || bucket[ny][nx] == 0) continue;
				cnt++;
			}
			bucket[i][j] += cnt;
		}
	}
}

void newCloud() {
	bool tmp[51][51] = {false, };
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(cloud[i][j] || bucket[i][j] < 2) continue;
			tmp[i][j] = true;
			bucket[i][j] -= 2;
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cloud[i][j] = tmp[i][j];
}

void solve() {
	moveCloud();
	copyWater();
	newCloud();
}

int calcSum() {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum += bucket[i][j];
		}
	}
	return sum;
}

int main(void) {
    FASTIO;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> bucket[i][j];
		}
	}
	cloud[n - 1][0] = cloud[n - 1][1] = cloud[n - 2][0] = cloud[n - 2][1] = true;

	for(int i = 0; i < m; i++) {
		cin >> d >> s;
		d--;
		solve();
	}
	cout << calcSum() << '\n';

    return 0;
}