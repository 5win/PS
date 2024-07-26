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
vector<int> A;

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());

	LL res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int target = -(A[i] + A[j]);
			int dist = (upper_bound(A.begin() + j + 1, A.end(), target) - A.begin()) - (lower_bound(A.begin() + j + 1, A.end(), target) - A.begin());
			res += dist;
		}
	}
	cout << res << '\n';

    return 0;
}