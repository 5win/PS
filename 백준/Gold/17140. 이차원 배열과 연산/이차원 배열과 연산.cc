#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int r, c, k;
int arr[101][101];
int rSize = 3, cSize = 3;

void operC() {

	int newRowSize = rSize;
	for(int j = 0; j < cSize; j++) {
		int cntArr[101] = {0, };
		for(int i = 0; i < rSize; i++) {
			cntArr[arr[i][j]]++;
		}

		vector<pair<int, int>> v;
		for(int i = 1; i <= 100; i++) {
			if(cntArr[i] > 0) {
				v.push_back({cntArr[i], i});
			}
		}
		sort(v.begin(), v.end());

		newRowSize = max(newRowSize, (int)v.size() * 2);
		newRowSize = (newRowSize > 100) ? 100 : newRowSize;

		for(int i = 0; i < rSize; i++)
			arr[i][j] = 0;
		for(int i = 0; i < v.size(); i++) {
			arr[i * 2][j] = v[i].second;
			arr[i * 2 + 1][j] = v[i].first;
		}
		// for(int i = 0; i < newRowSize; i += 2) {
		// 	arr[i][j] = v[i / 2].second;
		// 	arr[i + 1][j] = v[i / 2].first;
		// }
	}
	rSize = newRowSize;
}

void operR() {

	int newColSize = cSize;
	for(int i = 0; i < rSize; i++) {
		int cntArr[101] = {0, };
		for(int j = 0; j < cSize; j++) {
			cntArr[arr[i][j]]++;
		}

		vector<pair<int, int>> v;
		for(int j = 1; j <= 100; j++) {
			if(cntArr[j] > 0) {
				v.push_back({cntArr[j], j});
			}
		}
		sort(v.begin(), v.end());

		newColSize = max(newColSize, (int)v.size() * 2);
		newColSize = (newColSize > 100) ? 100 : newColSize;


		for(int j = 0; j <= cSize; j++)
			arr[i][j] = 0;
		for(int j = 0; j < v.size(); j++) {
			arr[i][j * 2] = v[j].second;
			arr[i][j * 2 + 1] = v[j].first;
		}
		// for(int j = 0; j < newColSize; j += 2) {
		// 	arr[i][j] = v[j / 2].second;
		// 	arr[i][j + 1] = v[j / 2].first;
		// }
	}
	cSize = newColSize;
}

int solve() {

	for(int i = 0; i <= 100; i++) {
		if(arr[r][c] == k)
			return i;

		if(rSize >= cSize) {
			operR();	
		} else {
			operC();
		}
	}
	return -1;
}

int main(void) {
    FASTIO;

	cin >> r >> c >> k;
	r--;
	c--;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solve() << '\n';

    return 0;
}