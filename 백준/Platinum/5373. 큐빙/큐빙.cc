#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

enum Color {
	ORANGE,
	YELLOW,
	RED,
	WHITE,
	GREEN,
	BLUE		
};

int n;
int cube[6][3][3];

/*
	 0
	415
	 2
	 3
*/
void initCube() {
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				cube[i][j][k] = ORANGE + i;
			}
		}
	}
}

// clock
void D() {
	int tmp[3] = {cube[0][2][2], cube[0][2][1], cube[0][2][0]};

	for(int i = 0; i < 3; i++) 
		cube[0][2][i] = cube[5][i][0];
	for(int i = 0; i < 3; i++) 
		cube[5][i][0] = cube[2][0][3 - i - 1];
	for(int i = 0; i < 3; i++)
		cube[2][0][i] = cube[4][i][2];
	for(int i = 0; i < 3; i++)
		cube[4][i][2] = tmp[i];
}

void U() {
	int tmp[3] = {cube[0][0][0], cube[0][0][1], cube[0][0][2]};

	for(int i = 0; i < 3; i++) 
		cube[0][0][i] = cube[4][3 - i - 1][0];
	for(int i = 0; i < 3; i++) 
		cube[4][i][0] = cube[2][2][i];
	for(int i = 0; i < 3; i++)
		cube[2][2][i] = cube[5][3 - i - 1][2];
	for(int i = 0; i < 3; i++)
		cube[5][i][2] = tmp[i];
}

void F() {
	int tmp[3] = {cube[1][2][0], cube[1][2][1], cube[1][2][2]};

	for(int i = 0; i < 3; i++) 
		cube[1][2][i] = cube[5][2][i];
	for(int i = 0; i < 3; i++) 
		cube[5][2][i] = cube[3][0][3 - i - 1];
	for(int i = 0; i < 3; i++)
		cube[3][0][3 - i - 1] = cube[4][2][i];
	for(int i = 0; i < 3; i++)
		cube[4][2][i] = tmp[i];
}

void B() {
	int tmp[3] = {cube[1][0][0], cube[1][0][1], cube[1][0][2]};

	for(int i = 0; i < 3; i++) 
		cube[1][0][i] = cube[4][0][i];
	for(int i = 0; i < 3; i++) 
		cube[4][0][i] = cube[3][2][3 - i - 1];
	for(int i = 0; i < 3; i++)
		cube[3][2][3 - i - 1] = cube[5][0][i];
	for(int i = 0; i < 3; i++)
		cube[5][0][i] = tmp[i];
}

void L() {
	int tmp[3] = {cube[0][0][0], cube[0][1][0], cube[0][2][0]};

	for(int i = 0; i < 3; i++) 
		cube[0][i][0] = cube[1][i][0];
	for(int i = 0; i < 3; i++) 
		cube[1][i][0] = cube[2][i][0];
	for(int i = 0; i < 3; i++)
		cube[2][i][0] = cube[3][i][0];
	for(int i = 0; i < 3; i++)
		cube[3][i][0] = tmp[i];
}

void R() {
	int tmp[3] = {cube[3][0][2], cube[3][1][2], cube[3][2][2]};

	for(int i = 0; i < 3; i++) 
		cube[3][i][2] = cube[2][i][2];
	for(int i = 0; i < 3; i++) 
		cube[2][i][2] = cube[1][i][2];
	for(int i = 0; i < 3; i++)
		cube[1][i][2] = cube[0][i][2];
	for(int i = 0; i < 3; i++)
		cube[0][i][2] = tmp[i];
}

void rotateClockWise(int target[3][3]) {
	int tmp[3][3];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			tmp[3 - j - 1][i] = target[i][j];
		}
	}
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			target[i][j] = tmp[i][j];
}

char convertColor(int num) {
	switch(num) {
		case 0:
			return 'o';
		case 1:
			return 'y';
		case 2:
			return 'r';
		case 3:
			return 'w';
		case 4:
			return 'g';
		case 5:
			return 'b';
	}
}

int main(void) {
    FASTIO;

	int t; cin >> t;
	while(t--) {
		initCube();
		cin >> n;
		string input;
		for(int i = 0; i < n; i++) {
			cin >> input;
			int dir = (input[1] == '+') ? 1 : 3;
			for(int j = 0; j < dir; j++) {
				switch(input[0]) {
					case 'U':
						U();
						rotateClockWise(cube[3]);
						break;
					case 'D':
						D();
						rotateClockWise(cube[1]);
						break;
					case 'F':
						F();
						rotateClockWise(cube[2]);
						break;
					case 'B':
						B();
						rotateClockWise(cube[0]);
						break;
					case 'L':
						L();
						rotateClockWise(cube[4]);
						break;
					case 'R':
						R();
						rotateClockWise(cube[5]);
						break;
				}
			}
		}

		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				cout << convertColor(cube[3][3 - i - 1][j]);
			}
			cout << '\n';
		}
	}

    return 0;
}