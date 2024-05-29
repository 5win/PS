#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int n, m, arr[1001][1001], from, to, weight, target;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> target;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			else
				arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		arr[from][to] = weight;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	int mx = 0;

	for (int i = 1; i <= n; i++) {
		mx = max(mx, arr[i][target] + arr[target][i]);
	}
	cout << mx;
}