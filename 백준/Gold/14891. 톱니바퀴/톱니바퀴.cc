#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

string wheel[4];
int k;

void decideDir(int d[4], int num) {
	for(int i = num + 1; i < 4; i++) {
		if(wheel[i - 1][2] == wheel[i][6])
			d[i] = 0;
		else 
			d[i] = -d[i - 1];
	}
	for(int i = num - 1; i >= 0; i--) {
		if(wheel[i + 1][6] == wheel[i][2])
			d[i] = 0;
		else 
			d[i] = -d[i + 1];
	}
}

void rotating(int d[4]) {
	for(int i = 0; i < 4; i++) {
		if(d[i] == -1) {
			wheel[i] = wheel[i].substr(1, 7) + wheel[i].substr(0, 1);
		} else if(d[i] == 1) {
			wheel[i] = wheel[i].substr(7, 1) + wheel[i].substr(0, 7);
		}
	}
}

int calcScore() {
	int ret = 0;
	for(int i = 0; i < 4; i++) {
		if(wheel[i][0] == '1') // S
			ret += pow(2, i);
	}
	return ret;
}

void solve(int num, int dir) {
	int d[4] = {0, };
	d[num] = dir;
	decideDir(d, num);
	rotating(d);
}

int main(void) {
    FASTIO;

	for(int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}
	cin >> k;
	int num, dir;
	while(k--) {
		cin >> num >> dir;
		num--;
		solve(num, dir);
	}
	cout << calcScore() << '\n';

    return 0;
}