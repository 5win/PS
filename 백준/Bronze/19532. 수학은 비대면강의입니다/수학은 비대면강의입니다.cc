#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int a, b, c, d, e, f;

bool equation1(int x, int y) {
	int result = a * x + b * y;
	return result == c;
}

bool equation2(int x, int y) {
	int result = d * x + e * y;
	return result == f;
}

int main(void) {
    FASTIO;

	cin >> a >> b >> c >> d >> e >> f;

	for(int i = -999; i < 1000; i++) {
		for(int j = -999; j < 1000; j++) {
			if(equation1(i, j) && equation2(i, j)) {
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}


    return 0;
}