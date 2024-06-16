#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n, m;
int matrix[101][101];

int main(void) {
    FASTIO;

    cin >> n >> m;
    int t = 2;
    while(t--) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int num; cin >> num;
                matrix[i][j] += num;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}