#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n;
int A[21][21];
int board[21][21];

void drawBorder(int y, int x, int d1, int d2) {
	// up left
	for(int i = 0; i <= d1; i++) {
		board[y + i][x - i] = 5;
	}
	// up right
	for(int i = 0; i <= d2; i++) {
		board[y + i][x + i] = 5;
	}
	// bottom left
	for(int i = 0; i <= d2; i++) {
		board[y + d1 + i][x - d1 + i] = 5;
	}
	// bottom right
	for(int i = 0; i <= d1; i++) {
		board[y + d2 + i][x + d2 - i] = 5;
	}
}

void fill5(int y, int x, int d1, int d2) {
	for(int i = y + 1; i < y + d1 + d2; i++) {
		bool start = false;
		for(int j = x - d1; j <= x + d2; j++) {
			if(!start) {
				if(board[i][j] == 5)
					start = true;
				continue;
			}
			if(start && board[i][j] == 5) {
				break;
			}
			board[i][j] = 5;
		}
	}
}

void fill1(int y, int x, int d1, int d2) {
	for(int i = 0; i < y + d1; i++) {
		for(int j = 0; j <= x; j++) {
			if(board[i][j] != 5)
				board[i][j] = 1;
		}
	}
}

void fill2(int y, int x, int d1, int d2) {
	for(int i = 0; i <= y + d2; i++) {
		for(int j = x + 1; j < n; j++) {
			if(board[i][j] != 5)
				board[i][j] = 2;
		}
	}
}

void fill3(int y, int x, int d1, int d2) {
	for(int i = y + d1; i < n; i++) {
		for(int j = 0; j < x - d1 + d2; j++) {
			if(board[i][j] != 5)
				board[i][j] = 3;
		}
	}
}

void fill4(int y, int x, int d1, int d2) {
	for(int i = y + d2 + 1; i < n; i++) {
		for(int j = x - d1 + d2; j < n; j++) {
			if(board[i][j] != 5) 
				board[i][j] = 4;
		}
	}
}

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

int calcResult() {
	int cnt[6] = {0, };
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cnt[board[i][j]] += A[i][j];
		}
	}
	int maxNum = *max_element(cnt + 1, cnt + 6);
	int minNum = *min_element(cnt + 1, cnt + 6);
	return maxNum - minNum;
}

int solve() {
	int ret = INF;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int d1 = 1; d1 < 20; d1++) {
				for(int d2 = 1; d2 < 20; d2++) {
					if(!inRange(i + d1, j - d1) || !inRange(i + d2, j + d2) || !inRange(i + d1 + d2, j - d1 + d2)) continue;

					memset(board, 0, sizeof(board));
					drawBorder(i, j, d1, d2);
					fill5(i, j, d1, d2);
					fill1(i, j, d1, d2);
					fill2(i, j, d1, d2);
					fill3(i, j, d1, d2);
					fill4(i, j, d1, d2);

					ret = min(ret, calcResult());
				}
			}
		}
	}
	return ret;
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	cout << solve() << '\n';

    return 0;
}