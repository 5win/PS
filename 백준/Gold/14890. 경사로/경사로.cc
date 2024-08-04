#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, l;
int board[101][101];

bool validate(vector<pair<int, int>>& arr) {
	for(int i = 1; i < arr.size(); i++) {
		if(arr[i - 1].first + 1 == arr[i].first && arr[i - 1].second >= l) {
			arr[i - 1].second -= l;
			continue;
		} else if(arr[i - 1].first == arr[i].first + 1 && arr[i].second >= l) {
			arr[i].second -= l;
			continue;
		} else {
			return false;
		}
	}
	return true;
}

int checkRow() {
	
	int ret = 0;
	vector<pair<int, int>> arr;
	for(int i = 0; i < n; i++) {
		arr.clear();
		int prev = board[i][0];
		int cnt = 1;
		for(int j = 1; j < n; j++) {
			if(board[i][j] == prev) {
				cnt++;
			} else {
				arr.push_back({prev, cnt});
				prev = board[i][j];	
				cnt = 1;
			}
		}
		arr.push_back({prev, cnt});
		if(validate(arr)) ret++;
	}
	return ret;
}

int checkCol() {
	int ret = 0;
	vector<pair<int, int>> arr;
	for(int j = 0; j < n; j++) {
		arr.clear();
		int prev = board[0][j];
		int cnt = 1;
		for(int i = 1; i < n; i++) {
			if(board[i][j] == prev) {
				cnt++;
			} else {
				arr.push_back({prev, cnt});
				prev = board[i][j];	
				cnt = 1;
			}
		}
		arr.push_back({prev, cnt});
		if(validate(arr)) ret++;
	}
	return ret;
}

int main(void) {
    FASTIO;

	cin >> n >> l;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << checkRow() + checkCol() << '\n';

    return 0;
}