#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n;

int solve() {
    int len = 1;
    int num = 1;
    while(true) {
        if(num % n == 0) {
            return len;
        } else {
            num = num % n * 10 + 1;
            len++;
        }
    }
}

int main(void) {
    FASTIO;

    while(cin >> n) {
        cout << solve() << '\n'; 
    }

    return 0;
}