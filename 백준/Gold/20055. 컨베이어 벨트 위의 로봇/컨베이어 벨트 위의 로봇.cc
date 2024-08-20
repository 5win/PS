#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Belt {
	bool robotExist = false;
	int A;
};

int n, k;
Belt belt[201];

void rotate() {
	Belt tmp = belt[2 * n - 1];
	for(int i = 2 * n - 1; i > 0; i--)
		belt[i] = belt[i - 1];
	belt[0] = tmp;
}

void moveRobot() {
	for(int i = n - 2; i >= 0; i--) {
		if(belt[i].robotExist && !belt[i + 1].robotExist && belt[i + 1].A > 0) {
			belt[i].robotExist = false;
			belt[i + 1].robotExist = true;
			belt[i + 1].A--;
		}
	}
}

void setRobot() {
	if(belt[0].A > 0) {
		belt[0].robotExist = true;
		belt[0].A--;
	}
}

void getRobot() {
	belt[n - 1].robotExist = false;
}

bool isFinish() {
	int cnt = 0;
	for(int i = 0; i < 2 * n; i++) {
		if(belt[i].A <= 0) {
			cnt++;
		}
	}
	return cnt >= k;
}

int solve() {
	int cnt = 1;
	while(true) {
		rotate();
		getRobot();

		moveRobot();
		getRobot();

		setRobot();
		
		if(isFinish()) break;
		cnt++;
	}
	return cnt;
}

int main(void) {
    FASTIO;

	cin >> n >> k;
	for(int i = 0; i < 2 * n; i++) {
		int a; cin >> a;
		belt[i] = {false, a};
	}
	cout << solve() << '\n';

    return 0;
}