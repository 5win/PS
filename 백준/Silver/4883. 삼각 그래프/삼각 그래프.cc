#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int n;
int arr[100001][5];

void solve() {
    arr[1][1] = INF;
    arr[1][3] += arr[1][2];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            int tmp = min(arr[i - 1][j - 1], arr[i - 1][j]);
            tmp = min(tmp, arr[i - 1][j + 1]);
            tmp = min(tmp, arr[i][j - 1]);
            arr[i][j] += tmp;
        }
    }
}

int main(void) {
    FASTIO;

    memset(arr, 0x3F, sizeof(arr));
    int t = 1;
    while(true) {
        cin >> n;
        if(n == 0) break;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> arr[i][j];
            }
        }

        solve();
        cout << t++ << ". " << arr[n][2] << '\n';
    }

    return 0;
}