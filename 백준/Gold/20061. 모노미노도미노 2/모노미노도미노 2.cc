#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

const int SIZE = 10;
int n, score; 
bool board[15][15];

bool inRange(int y, int x) {
	return 0 <= y && y < SIZE && 0 <= x && x < SIZE;
}

void blockDown(int y1, int x1, int y2, int x2) {
	y1++;
	y2++;
	while(true) {
		if(!inRange(y1, x1) || !inRange(y2, x2) || board[y1][x1] || board[y2][x2]) {
			board[y1 - 1][x1] = true;
			board[y2 - 1][x2] = true;
			break;
		}
		y1++;
		y2++;
	}
}

void blockRight(int y1, int x1, int y2, int x2) {
	x1++;
	x2++;
	while(true) {
		if(!inRange(y1, x1) || !inRange(y2, x2) || board[y1][x1] || board[y2][x2]) {
			board[y1][x1 - 1] = true;
			board[y2][x2 - 1] = true;
			break;
		}
		x1++;
		x2++;
	}
}

void removeRow(int y) {
	for(int i = y; i > 0; i--) {
		for(int j = 0; j < 4; j++) {
			board[i][j] = board[i - 1][j];
		}
	}
}

void removeCol(int x) {
	for(int j = x; j > 0; j--) {
		for(int i = 0; i < 4; i++) {
			board[i][j] = board[i][j - 1];
		}
	}
}

void checkGreen() {
	for(int i = SIZE - 1; i >= 4;) {
		bool getScore = true;
		for(int j = 0; j < 4; j++) {
			if(!board[i][j]) {
				getScore = false;
				break;
			}
		}
		if(getScore) {
			score++;
			removeRow(i);
			continue;
		}
		i--;
	}
}

void checkBlue() {
	for(int j = SIZE - 1; j >= 4;) {
		bool getScore = true;
		for(int i = 0; i < 4; i++) {
			if(!board[i][j]) {
				getScore = false;
				break;
			}
		}
		if(getScore) {
			score++;
			removeCol(j);
			continue;
		}
		j--;
	}
}

void checkLowGreen() {
	int cnt = 0;
	for(int i = 4; i <= 5; i++) {
		for(int j = 0; j < 4; j++) {
			if(board[i][j]) {
				cnt++;
				break;
			}
		}
	}

	for(int i = SIZE - 1; i >= cnt; i--) {
		for(int j = 0; j < 4; j++) {
			board[i][j] = board[i - cnt][j];
		}
	}
}

void checkLowBlue() {
	int cnt = 0;
	for(int j = 4; j <= 5; j++) {
		for(int i = 0; i < 4; i++) {
			if(board[i][j]) {
				cnt++;
				break;
			}
		}
	}

	for(int j = SIZE - 1; j >= cnt; j--) {
		for(int i = 0; i < 4; i++) {
			board[i][j] = board[i][j - cnt];
		}
	}
}

int calcCnt() {
	int ret = 0;
	for(int i = 4; i < SIZE; i++) {
		for(int j = 0; j < 4; j++) {
			if(board[i][j]) ret++;
			if(board[j][i]) ret++;
		}
	}
	return ret;
}

void solve(int t, int y, int x) {
	if(t == 1) {
		blockDown(y, x, y, x);
		blockRight(y, x, y, x);
	} else if(t == 2) {
		blockDown(y, x, y, x + 1);
		blockRight(y, x, y, x + 1);
	} else if(t == 3) {
		blockDown(y, x, y + 1, x);
		blockRight(y, x, y + 1, x);
	}

	checkGreen();
	checkBlue();

	checkLowGreen();
	checkLowBlue();
}

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int t, x, y;
		cin >> t >> y >> x;

		solve(t, y, x);
	}

	cout << score << '\n';
	cout << calcCnt() << '\n';

    return 0;
}