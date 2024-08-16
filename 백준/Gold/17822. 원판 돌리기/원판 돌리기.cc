#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m, t;
int board[51][51];

bool inRange(int y) {
	return 0 <= y && y < n;
}

void rotateClock(int num) {
	int tmp = board[num][m - 1];
	for(int i = m - 1; i > 0; i--)
		board[num][i] = board[num][i - 1];
	board[num][0] = tmp;
}

void rotateClockwise(int num) {
	int tmp = board[num][0];
	for(int i = 0; i < m - 1; i++)
		board[num][i] = board[num][i + 1];
	board[num][m - 1] = tmp;
}

bool removeNum() {
	bool sameExist = false;
	int tmp[51][51];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmp[i][j] = board[i][j];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int cur = board[i][j];
			if(cur == 0) continue;
			
			bool findSame = false;
			if(board[i][(j + 1) % m] == cur) {
				tmp[i][(j + 1) % m] = 0;
				findSame = true;
			}

			if(board[i][(j - 1 + m) % m] == cur) {
				tmp[i][(j - 1 + m) % m] = 0;
				findSame = true;
			}

			if(inRange(i + 1) && board[i + 1][j] == cur) {
				tmp[i + 1][j] = 0;
				findSame = true;
			}

			if(inRange(i - 1) && board[i - 1][j] == cur) {
				tmp[i - 1][j] = 0;
				findSame = true;
			}

			if(findSame) {
				tmp[i][j] = 0;
				sameExist = true;
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)	
			board[i][j] = tmp[i][j];

	return sameExist;
}

void extractMean() {
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] != 0) {
				sum += board[i][j];
				cnt++;
			}
		}
	}

	double mean = (double)sum / cnt;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] == 0) continue;
			if(board[i][j] < mean)
				board[i][j]++;
			else if(board[i][j] > mean)
				board[i][j]--;
		}
	}
}

void solve(int x, int d, int k) {

	for(int i = 0; i < n; i++) {
		if((i + 1) % x != 0) continue;
		for(int j = 0; j < k; j++) {
			if(d == 0)
				rotateClock(i);
			else
				rotateClockwise(i);
		}
	}

	if(!removeNum()) {
		extractMean();
	}
}

int main(void) {
    FASTIO;

	cin >> n >> m >> t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while(t--) {
		int x, d, k;
		cin >> x >> d >> k;
		solve(x, d, k);
	}

	int sum = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sum += board[i][j];
	cout << sum << '\n';

    return 0;
}