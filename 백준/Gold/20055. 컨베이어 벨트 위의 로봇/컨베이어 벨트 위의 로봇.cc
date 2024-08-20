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
vector<int> robotLoc;
int deadCnt = 0;

void rotate() {
	Belt tmp = belt[2 * n - 1];
	for(int i = 2 * n - 1; i > 0; i--)
		belt[i] = belt[i - 1];
	belt[0] = tmp;

	for(int i = deadCnt; i < robotLoc.size(); i++) {
		robotLoc[i] = (robotLoc[i] + 1) % (2 * n);
	}
}

void moveRobot() {
	for(int rNum = deadCnt; rNum < robotLoc.size(); rNum++) {
		int cLoc = robotLoc[rNum];
		int nLoc = (cLoc + 1) % (2 * n);
		if(belt[nLoc].robotExist || belt[nLoc].A == 0) continue;
		belt[cLoc].robotExist = false;
		belt[nLoc].robotExist = true;
		belt[nLoc].A--;
		robotLoc[rNum] = nLoc;
	}
}

void setRobot() {
	if(belt[0].A > 0) {
		belt[0].robotExist = true;
		belt[0].A--;

		robotLoc.push_back(0);
	}
}

void getRobot() {
	if(belt[n - 1].robotExist) {
		belt[n - 1].robotExist = false;
		deadCnt++;
	}
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