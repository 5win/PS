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
int A[1000001];
int B, C;

int main(void) {
    FASTIO;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	LL res = n;
	for(int i = 0; i < n; i++) {
		A[i] = max(0, A[i] - B);
	}	

	for(int i = 0; i < n; i++) {
		if(A[i] % C == 0)
			res += A[i] / C;
		else
			res += A[i] / C + 1;
	}
	cout << res << '\n';

    return 0;
}