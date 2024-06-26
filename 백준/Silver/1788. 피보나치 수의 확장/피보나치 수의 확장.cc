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
int fibo[int(2e6 + 1)];

int main(void) {
    FASTIO;

    cin >> n;
    
    fibo[int(1e6)] = 0;
    fibo[int(1e6 + 1)] = 1;
    for(int i = int(1e6 + 2); i <= 2e6; i++) 
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    for(int i = int(1e6 - 1); i >= 0; i--)
        fibo[i] = (fibo[i + 2] - fibo[i + 1]) % MOD;
    
    int idx = n + int(1e6);

    if(fibo[idx] > 0) cout << "1\n";
    else if(fibo[idx] == 0) cout << "0\n";
    else cout << "-1\n";

    cout << abs(fibo[idx]) << '\n';

    return 0;
}