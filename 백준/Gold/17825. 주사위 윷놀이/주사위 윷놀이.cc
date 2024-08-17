#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Node {
	int score, next;
};

int num[11];
Node board[35];
bool visited[35];
int loc[5];
int sum[5];
int res;

void init() {
	for(int i = 0; i <= 20; i++) {
		board[i] = {i * 2, i + 1};
	}
	board[21] = {0, 21};
	board[22] = {13, 23};
	board[23] = {16, 24};
	board[24] = {19, 30};

	board[25] = {22, 26};
	board[26] = {24, 30};

	board[27] = {28, 28};
	board[28] = {27, 29};
	board[29] = {26, 30};

	board[30] = {25, 31};
	board[31] = {30, 32};
	board[32] = {35, 20};
}

void calcMax() {
	int ret = 0;
	for(int i = 0; i < 4; i++) {
		ret += sum[i];
	}
	res = max(res, ret);
}

void dfs(int here) {
	if(here == 10) {
		calcMax();
		return;
	}

	for(int i = 0; i < 4; i++) {
		int next = loc[i];

		if(next == 5) {
			next = 22;
		} else if(next == 10) {
			next = 25;
		} else if(next == 15) {
			next = 27;
		} else {
			next = board[next].next;
		}

		for(int j = 0; j < num[here] - 1; j++) {
			next = board[next].next;
		}

		if(next != 21 && visited[next]) continue;

		int tmp = loc[i];
		loc[i] = next;
		sum[i] += board[next].score;
		visited[tmp] = false;
		visited[next] = true;
		dfs(here + 1);
		visited[next] = false;
		visited[tmp] = true;
		sum[i] -= board[next].score;
		loc[i] = tmp;
	}
}

int main(void) {
    FASTIO;

	for(int i = 0; i < 10; i++)
		cin >> num[i];	
	
	init();
	dfs(0);
	cout << res << '\n';	


    return 0;
}